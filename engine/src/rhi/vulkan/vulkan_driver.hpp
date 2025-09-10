#pragma once
#include "engine/rhi.hpp"
#include <vector>

#include <vulkan/vulkan.h>

namespace stmp::rhi
{
    class VulkanDriver final : public Device
    {
    public:
        VulkanDriver() = default;
        ~VulkanDriver() override;

        bool init(LUUID luuid, bool debug);

    private:
        bool fetch_instance_exts();
        bool enable_validation_layers() const;
        bool has_extensions(std::initializer_list<const char*> extensions) const;

    private:
        bool m_init;
        bool m_debug;
        VkInstance m_instance;
        std::vector<const char*> m_instance_exts;
        std::vector<const char*> m_validation_layers;
    };

} // namespace stmp::rhi