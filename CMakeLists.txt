cmake_minimum_required(VERSION 3.16.3)
project(Casadi_mixed_integer_example VERSION 1.0)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${PROJECT_SOURCE_DIR}/cmake)

find_package(CASADI REQUIRED)

add_executable(${PROJECT_NAME}_1 src/example1.cpp)
add_executable(${PROJECT_NAME}_2 src/example2.cpp)

target_link_libraries( ${PROJECT_NAME}_1 ${CASADI_LIBRARIES} )
target_link_libraries( ${PROJECT_NAME}_2 ${CASADI_LIBRARIES} )