set(SRCROOT ${PROJECT_SOURCE_DIR}/src/)
set(INCROOT 
	${SRCROOT})

set(SRC
    ${SRCROOT}main.cpp
    ${SRCROOT}ecs/raylib/Raylib.cpp
    ${SRCROOT}ecs/raylib/Raylib.hpp
    ${SRCROOT}ecs/entity/Entity.cpp
    ${SRCROOT}ecs/entity/Entity.hpp
    ${SRCROOT}ecs/component/Component.hpp)

add_subdirectory(ecs)

set(TARGET_NAME indie)
add_executable(${TARGET_NAME} ${SRC})
target_link_libraries(${TARGET_NAME} PRIVATE raylib)
add_custom_command(TARGET ${TARGET_NAME} 
	POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:${TARGET_NAME}> ${PROJECT_SOURCE_DIR})