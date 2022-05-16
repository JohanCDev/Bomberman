set(SRCROOT ${PROJECT_SOURCE_DIR}/src/)
set(INCROOT 
	${INCROOT}
	${SRCROOT})

set(SRC)

add_subdirectory(ecs)

set(TARGET_NAME arcade)
add_executable(${TARGET_NAME} ${SRCROOT}/main.cpp)
target_link_libraries(${TARGET_NAME} PRIVATE raylib)
add_custom_command(TARGET ${TARGET_NAME} 
	POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:${TARGET_NAME}> ${PROJECT_SOURCE_DIR})