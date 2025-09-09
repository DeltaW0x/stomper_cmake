#include <engine/math/math.hpp>
#include <spdlog/spdlog.h>
#include <engine/rhi.hpp>

using namespace stmp;
int main()
{
    rhi::Device* device = rhi::create_vulkan_device();
    delete device;
}
