#include <engine/math/math.hpp>
#include <spdlog/spdlog.h>
#include <engine/rhi.hpp>
#include <SDL3/SDL_init.h>

using namespace stmp;
int main()
{
    SDL_Init(SDL_INIT_VIDEO);
    rhi::Device* device = rhi::create_vulkan_device({}, true);
    delete device;
}
