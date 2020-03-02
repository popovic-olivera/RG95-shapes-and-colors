cmake_minimum_required(VERSION 3.10)
project(RG95-shapes-and-colors)

set(CMAKE_CXX_STANDARD 14)

link_libraries(GL)
link_libraries(GLU)
link_libraries(glut)

FILE(COPY images/pozadina.bmp DESTINATION "${CMAKE_BINARY_DIR}/images")
FILE(COPY images/tekstura_kutije.bmp DESTINATION "${CMAKE_BINARY_DIR}/images")

file(GLOB_RECURSE sources
    "src/*.hpp"
    "src/*.cpp"
)

add_executable(RG95-shapes-and-colors ${sources}) 
