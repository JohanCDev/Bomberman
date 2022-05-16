set(SRCROOT ${PROJECT_SOURCE_DIR}/src/ecs/entity)
set(INCROOT 
	${INCROOT}
	${SRCROOT})

set(SRC
	${SRC}
	${SRCROOT}/Entity.hpp
	${SRCROOT}/Entity.cpp
	PARENT_SCOPE)