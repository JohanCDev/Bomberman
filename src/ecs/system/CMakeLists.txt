set(SRCROOT ${PROJECT_SOURCE_DIR}/src/ecs/system)
set(INCROOT 
	${INCROOT}
	${SRCROOT})

set(SRC
	${SRC}
	${SRCROOT}/System.hpp
	PARENT_SCOPE)