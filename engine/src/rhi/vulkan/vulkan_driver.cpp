#include "vulkan_driver.hpp"
#include <SDL3/SDL_platform_defines.h>
#include <spdlog/spdlog.h>

#ifdef SDL_PLATFORM_LINUX
#define VK_USE_PLATFORM_XCB_KHR
#define VK_USE_PLATFORM_XLIB_KHR
#define VK_USE_PLATFORM_WAYLAND_KHR
#endif

#define VOLK_IMPLEMENTATION
#include <volk.h>
#include <vulkan/vk_enum_string_helper.h>

namespace stmp::rhi
{

    VulkanDriver::~VulkanDriver()
    {
    }

    bool VulkanDriver::init(LUUID luuid, bool debug)
    {
        if (auto result = volkInitialize(); result != VK_SUCCESS)
        {
            spdlog::error("Failed to initialize volk: {}", string_VkResult(result));
            return false;
        }
        volkFinalize();
        return true;
    }

} // namespace stmp::rhi
