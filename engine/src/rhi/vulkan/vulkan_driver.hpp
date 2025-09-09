#pragma once
#include <engine/rhi.hpp>

namespace stmp::rhi
{
    class VulkanDriver final : public Device
    {
    public:
        VulkanDriver() = default;
        ~VulkanDriver() override;

        bool init(LUUID luuid, bool debug);
    };

} // namespace stmp::rhi