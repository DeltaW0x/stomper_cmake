#include "sys_rhi.hpp"
#include "engine/rhi.hpp"
#include <spdlog/spdlog.h>
#include <SDL3/SDL_platform_defines.h>

#if defined(SDL_PLATFORM_WINDOWS) || defined(SDL_PLATFORM_LINUX) || defined(SDL_PLATFORM_APPLE)
#include "vulkan/vulkan_driver.hpp"
#endif

namespace stmp::rhi
{
    Device* create_metal_device(bool low_power, bool debug)
    {
#ifndef SDL_PLATFORM_APPLE
        spdlog::error("You may create a metal rhi device only on apple platforms");
        return nullptr;
#endif
        spdlog::error("The metal rhi device is not yet implemented");
        std::abort();
    }

    Device* create_d3d12_device(LUUID luuid, bool debug, bool gpu_va)
    {
#ifndef SDL_PLATFORM_WINDOWS
        spdlog::error("You may create a d3d12 rhi device only on windows platforms");
        return nullptr;
#endif
        spdlog::error("The d3d12 rhi device is not yet implemented");
        std::abort();
    }

    Device* create_vulkan_device(LUUID luuid, bool debug)
    {
        #if defined(SDL_PLATFORM_WINDOWS) || defined(SDL_PLATFORM_LINUX) || defined(SDL_PLATFORM_APPLE)

        auto driver = std::make_unique<VulkanDriver>();
        if (!driver->init(luuid, debug))
        {
            spdlog::error("Failed to initialize Vulkan rhi device");
            return nullptr;
        }
        return driver.release();

        #endif
        spdlog::error("You may create a vulkan rhi device only on windows, linux and apple platforms");
        return nullptr;
    }
}