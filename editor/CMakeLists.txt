project(Editor LANGUAGES C CXX VERSION 1.0.0)

file(GLOB_RECURSE
	EDITOR_SOURCES
		${PROJECT_SOURCE_DIR}/src/*.h
		${PROJECT_SOURCE_DIR}/src/*.c
		${PROJECT_SOURCE_DIR}/src/*.hpp
		${PROJECT_SOURCE_DIR}/src/*.cpp
		${PROJECT_SOURCE_DIR}/src/*.cppm)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${EDITOR_SOURCES})

add_executable(Editor ${EDITOR_SOURCES})
target_include_directories(Editor PRIVATE ${PROJECT_SOURCE_DIR}/src)
target_link_libraries(Editor PRIVATE Engine)

if(CMAKE_IMPORT_LIBRARY_SUFFIX)
	add_custom_command(
        TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_EDITOR_DLLS:${PROJECT_NAME}> $<TARGET_FILE_DIR:${PROJECT_NAME}>
        COMMAND_EXPAND_LISTS)
endif()

