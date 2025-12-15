cmake_minimum_required(VERSION 3.16.3)
project(Casadi_mixed_integer_example VERSION 1.0)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -O3")
set(CMAKE_BUILD_TYPE Release)
add_compile_options(-D_GLIBCXX_USE_CXX11_ABI=0)
add_definitions(-w)


find_package(Eigen3 REQUIRED)

# --- Get CasADi python package path into a CMake variable ---
find_package(Python3 REQUIRED COMPONENTS Interpreter)
execute_process(
    COMMAND ${Python3_EXECUTABLE} -c
            "import casadi, os; print(os.path.dirname(casadi.__file__))"
    OUTPUT_VARIABLE CASADI_PKG_PATH
    OUTPUT_STRIP_TRAILING_WHITESPACE
    RESULT_VARIABLE _casadi_rc
    ERROR_VARIABLE _casadi_err
)
if(NOT _casadi_rc EQUAL 0 OR CASADI_PKG_PATH STREQUAL "")
    message(FATAL_ERROR
        "Failed to locate CasADi python package path.\n"
        "Python: ${Python3_EXECUTABLE}\n"
        "Error: ${_casadi_err}\n"
        "Tip: ensure CasADi is installed for this Python (python3 -c \"import casadi\")."
    )
endif()
message(STATUS "CASADI_PKG_PATH: ${CASADI_PKG_PATH}")
find_library(CASADI_LIBRARIES
    NAMES casadi libcasadi
    PATHS ${CASADI_PKG_PATH}
    NO_DEFAULT_PATH
)
include_directories(${CASADI_PKG_PATH}/include)



add_executable(${PROJECT_NAME}_1 src/example1.cpp)
add_executable(${PROJECT_NAME}_2 src/example2.cpp)

target_link_libraries( ${PROJECT_NAME}_1 ${CASADI_LIBRARIES} Eigen3::Eigen)
target_link_libraries( ${PROJECT_NAME}_2 ${CASADI_LIBRARIES} Eigen3::Eigen)