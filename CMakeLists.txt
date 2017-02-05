cmake_minimum_required (VERSION 2.8)

set(PROJECT Client)
project (${PROJECT})

set(SOURCES ${SOURCES}
	main.cpp
)

find_package(SDL2 REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)

include_directories(
	includes
)

add_executable(${PROJECT} ${SOURCES} ${LIBS})

target_link_libraries(${PROJECT}
	${SDL2_LIBRARIES}
	${OPENGL_LIBRARIES}
	${GLEW_LIBRARIES}
)
