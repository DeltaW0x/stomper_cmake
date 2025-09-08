cmake_minimum_required(VERSION 3.8)
project(Stomper)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_OBJCXX_STANDARD 20)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

include(${CMAKE_SOURCE_DIR}/scripts/Functions.cmake)
include(${CMAKE_SOURCE_DIR}/scripts/Dependencies.cmake)

add_subdirectory(engine)
add_subdirectory(editor)
add_subdirectory(tests)

get_all_targets(DEPS_TARGETS)
set_target_properties(
        ${DEPS_TARGETS}
        PROPERTIES
        FOLDER "Dependencies")

set_target_properties(
        Tests
        Engine
        Editor
        PROPERTIES
        FOLDER "Runtime")
