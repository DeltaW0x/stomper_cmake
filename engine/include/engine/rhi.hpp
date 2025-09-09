#pragma once
#include "common.hpp"

namespace stmp::rhi
{
    MAKE_HANDLE(Buffer)
    MAKE_HANDLE(Texture)

    typedef struct LUUID
    {
        uint8_t data[16] = {};
    } LUUID;

    class Device
    {
    protected:
        Device() = default;
    public:
        virtual ~Device() = default;
    };

    [[nodiscard]] Device* create_metal_device(bool low_power = false, bool debug = false);
    [[nodiscard]] Device* create_d3d12_device(LUUID luuid = {}, bool debug = false, bool gpu_va = false);
    [[nodiscard]] Device* create_vulkan_device(LUUID luuid = {}, bool debug = false);

}