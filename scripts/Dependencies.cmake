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