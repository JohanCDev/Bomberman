set(SRCROOT ${PROJECT_SOURCE_DIR}/src/ecs/component)
set(INCROOT 
	${INCROOT}
	${SRCROOT})

set(SRC
	${SRC}
	${SRCROOT}/Component.hpp
	PARENT_SCOPE)