project(Engine LANGUAGES C CXX VERSION 1.0.0)

file(GLOB_RECURSE ENGINE_SOURCES
		${PROJECT_SOURCE_DIR}/src/*.h
		${PROJECT_SOURCE_DIR}/src/*.c
		${PROJECT_SOURCE_DIR}/src/*.hpp
		${PROJECT_SOURCE_DIR}/src/*.cpp
		${PROJECT_SOURCE_DIR}/src/*.cppm)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${ENGINE_SOURCES})

add_library(Engine STATIC ${ENGINE_SOURCES})
target_compile_definitions(Engine PUBLIC "VK_NO_PROTOTYPES")
target_include_directories(Engine PRIVATE ${PROJECT_SOURCE_DIR}/src)
target_include_directories(Engine PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_link_libraries(Engine PUBLIC
		SDL3::SDL3-static
		spdlog::spdlog
		Vulkan::Headers
		Vulkan::UtilityHeaders
		volk::volk_headers
		libdeflate_static)

if(CMAKE_SYSTEM_PROCESSOR STREQUAL "x86_64")
	if (MSVC)
		target_compile_options(Engine PUBLIC /arch:AVX2)
	else()
		target_compile_options(Engine PUBLIC -mavx2 -mfma)
	endif()
endif()