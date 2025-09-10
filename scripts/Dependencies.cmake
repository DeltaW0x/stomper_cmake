include(${CMAKE_CURRENT_LIST_DIR}/CPM.cmake)

CPMAddPackage(
        NAME SDL3
        SOURCE_DIR ${CMAKE_SOURCE_DIR}/third_party/sdl
        OPTIONS "SDL_AUDIO OFF" "SDL_GPU OFF" "SDL_RENDERER OFF" "SDL_SHARED ON")

CPMAddPackage(
        NAME spdlog
        SOURCE_DIR ${CMAKE_SOURCE_DIR}/third_party/spdlog)

CPMAddPackage(
        NAME catch2
        SOURCE_DIR ${CMAKE_SOURCE_DIR}/third_party/catch2)

CPMAddPackage(
        NAME vulkan_headers
        SOURCE_DIR ${CMAKE_SOURCE_DIR}/third_party/vulkan_headers)

CPMAddPackage(
        NAME vulkan_utility_libraries
        SOURCE_DIR ${CMAKE_SOURCE_DIR}/third_party/vulkan_utility_libraries)

CPMAddPackage(
        NAME volk
        SOURCE_DIR ${CMAKE_SOURCE_DIR}/third_party/volk
        OPTIONS "VULKAN_HEADERS_INSTALL_DIR ${vulkan_headers_SOURCE_DIR}/include")