set(SRCROOT ${PROJECT_SOURCE_DIR}/src/ecs/raylib)
set(INCROOT 
	${INCROOT}
	${SRCROOT})

set(SRC
	${SRC}
	${SRCROOT}/Raylib.hpp
	${SRCROOT}/Raylib.cpp
	PARENT_SCOPE)