include(${CMAKE_CURRENT_LIST_DIR}/CPM.cmake)

CPMAddPackage(
        NAME SDL3
        SOURCE_DIR ${CMAKE_SOURCE_DIR}/third_party/sdl
        OPTIONS "SDL_AUDIO OFF" "SDL_GPU OFF" "SDL_RENDERER OFF" "SDL_SHARED OFF" "SDL_STATIC ON")

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

CPMAddPackage(
        NAME libdeflate
        SOURCE_DIR ${CMAKE_SOURCE_DIR}/third_party/libdeflate)
if(libdeflate_ADDED)

    file(GLOB COMMON_SOURCES ${libdeflate_SOURCE_DIR}/lib/*.c)
    file(GLOB COMMON_HEADERS ${libdeflate_SOURCE_DIR}/lib/*.h)

    if(SDL_CPU_X64)
        file(GLOB X86_SOURCES ${libdeflate_SOURCE_DIR}/lib/x86/*.c)
        file(GLOB X86_HEADERS ${libdeflate_SOURCE_DIR}/lib/x86/*.h)
        list(APPEND COMMON_SOURCES ${X86_SOURCES})
        list(APPEND COMMON_HEADERS ${X86_HEADERS})
    elseif(SDL_CPU_ARM64)
        file(GLOB ARM64_SOURCES ${libdeflate_SOURCE_DIR}/lib/arm/*.c)
        file(GLOB ARM64_HEADERS ${libdeflate_SOURCE_DIR}/lib/arm/*.h)
        list(APPEND COMMON_SOURCES ${ARM64_SOURCES})
        list(APPEND COMMON_HEADERS ${ARM64_HEADERS})
    else()
        message(FATAL_ERROR "Unsupported libdeflate architecture")
    endif()

    add_library(libdeflate_static STATIC ${COMMON_SOURCES} ${COMMON_HEADERS})
    target_include_directories(libdeflate_static PUBLIC ${libdeflate_SOURCE_DIR})
    if(WIN32)
        target_compile_options(libdeflate_static PRIVATE /wd4244 /wd4127 /wd4267 /wd4100 /wd4245 /wd4456 /wd4018 /wd4146 /wd4310)
    endif()
endif()