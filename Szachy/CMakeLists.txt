cmake_minimum_required(VERSION 3.1)
project(Szachy)

set(CMAKE_CXX_STANDARD 11)

add_compile_options(-Wall)

include_directories(${PROJECT_SOURCE_DIR})
include_directories(${PROJECT_SOURCE_DIR}/dir)

file(GLOB SOURCES "classes/*.cpp")
add_executable(Szachy ${SOURCES})


target_include_directories(Szachy PUBLIC include)

set(SFML_DIR ${CMAKE_SOURCE_DIR}/lib/sfml/)
file(GLOB SFML_LIBS  ${SFML_DIR}*)
target_link_libraries(Szachy ${SFML_LIBS})