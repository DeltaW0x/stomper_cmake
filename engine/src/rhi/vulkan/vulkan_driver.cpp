#include "vulkan_driver.hpp"
#include <SDL3/SDL_platform_defines.h>
#include <spdlog/spdlog.h>

#ifdef SDL_PLATFORM_LINUX
#define VK_USE_PLATFORM_XCB_KHR
#define VK_USE_PLATFORM_XLIB_KHR
#define VK_USE_PLATFORM_WAYLAND_KHR
#endif

#define VOLK_IMPLEMENTATION
#include <SDL3/SDL_vulkan.h>
#include <volk.h>
#include <vulkan/vk_enum_string_helper.h>

namespace stmp::rhi
{

    VulkanDriver::~VulkanDriver()
    {
        if (m_init)
        {
            vkDestroyInstance(m_instance, nullptr);
        }
    }

    bool VulkanDriver::init(LUUID luuid, bool debug)
    {
        m_init = false;
        m_validation_layers.push_back("VK_LAYER_KHRONOS_validation");

        if (const auto result = volkInitialize(); result != VK_SUCCESS)
        {
            spdlog::error("Failed to initialize volk: {}", string_VkResult(result));
            return false;
        }

        m_debug = debug && enable_validation_layers();
        if (!fetch_instance_exts())
        {
            spdlog::error("Failed to fetch Vulkan instance extensions: {}", SDL_GetError());
            return false;
        }
        if (debug && !m_debug)
        {
            spdlog::error("Failed to enable Vulkan validation layers, disabling debug");
        }

        VkApplicationInfo app_info{
                .sType = VK_STRUCTURE_TYPE_APPLICATION_INFO,
                .pNext = nullptr,
                .pApplicationName = "test_application",
                .applicationVersion = VK_MAKE_API_VERSION(0, 1, 0, 0),
                .pEngineName = "Stomper",
                .engineVersion = VK_MAKE_API_VERSION(0, 1, 0, 0),
                .apiVersion = VK_API_VERSION_1_2,
        };

        VkInstanceCreateInfo instance_info{
                .sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO,
                .pNext = nullptr,
                .pApplicationInfo = &app_info,
                .enabledLayerCount = m_debug ? static_cast<u32>(m_validation_layers.size()) : 0,
                .ppEnabledLayerNames = m_validation_layers.data(),
                .enabledExtensionCount = static_cast<u32>(m_instance_exts.size()),
                .ppEnabledExtensionNames = m_instance_exts.data(),
        };

#ifdef SDL_PLATFORM_APPLE
        instance_info.flags = VK_INSTANCE_CREATE_ENUMERATE_PORTABILITY_BIT_KHR,
#endif

        if (const auto result = vkCreateInstance(&instance_info, nullptr, &m_instance); result != VK_SUCCESS)
        {
            spdlog::error("Failed to create Vulkan instance: {}", string_VkResult(result));
            return false;
        }

        volkLoadInstance(m_instance);

        spdlog::info("Vulkan rhi initialized correctly");
        if (m_debug) spdlog::warn("Vulkan validation layers enabled");

        m_init = true;
        return true;
    }

    bool VulkanDriver::fetch_instance_exts()
    {
        u32 ext_count;
        if (const auto exts = SDL_Vulkan_GetInstanceExtensions(&ext_count); exts != nullptr)
        {
            for (u32 i = 0; i < ext_count; i++)
            {
                m_instance_exts.emplace_back(exts[i]);
            }
            if (m_debug)
            {
                if (has_extensions({VK_EXT_DEBUG_UTILS_EXTENSION_NAME}))
                {
                    m_instance_exts.emplace_back(VK_EXT_DEBUG_UTILS_EXTENSION_NAME);
                }
                else
                {
                    m_debug = false;
                }
            }
            return true;
        }
        return false;
    }

    bool VulkanDriver::enable_validation_layers() const
    {
        u32 layer_count;
        vkEnumerateInstanceLayerProperties(&layer_count, nullptr);
        std::vector<VkLayerProperties> avail_layers(layer_count);
        vkEnumerateInstanceLayerProperties(&layer_count, avail_layers.data());

        for (const char *layerName: m_validation_layers)
        {
            bool layerFound = false;
            for (const auto &layerProperties: avail_layers)
            {
                if (strcmp(layerName, layerProperties.layerName) == 0)
                {
                    layerFound = true;
                    break;
                }
            }
            if (!layerFound)
            {
                return false;
            }
        }
        return true;
    }

    bool VulkanDriver::has_extensions(std::initializer_list<const char *> extensions) const
    {
        u32 ext_count;
        vkEnumerateInstanceExtensionProperties(nullptr, &ext_count, nullptr);
        std::vector<VkExtensionProperties> avail_exts(ext_count);
        vkEnumerateInstanceExtensionProperties(nullptr, &ext_count, avail_exts.data());

        for (const char *ext_name: extensions)
        {
            bool layerFound = false;
            for (const auto &ext_property: avail_exts)
            {
                if (strcmp(ext_name, ext_property.extensionName) == 0)
                {
                    layerFound = true;
                    break;
                }
            }
            if (!layerFound)
            {
                return false;
            }
        }
        return true;
    }

} // namespace stmp::rhi
