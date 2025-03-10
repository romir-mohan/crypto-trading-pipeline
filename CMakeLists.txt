cmake_minimum_required(VERSION 3.20)

project(intern LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Python3 3.12 COMPONENTS Interpreter Development EXACT REQUIRED)
find_package(pybind11 REQUIRED)

find_package(cpr REQUIRED)
find_package(nlohmann_json REQUIRED)
find_package(GTest REQUIRED)
enable_testing()

# Gather source files
file(GLOB INTERN_PROJECT_MAIN src/cppsrc/main.cpp)
file(GLOB_RECURSE INTERN_PROJECT_HEADERS src/cppsrc/*.hpp)
file(GLOB_RECURSE INTERN_PROJECT_TESTS src/cppsrc/test/*.cpp)

# Add the main executable
add_executable(intern_project ${INTERN_PROJECT_MAIN} ${INTERN_PROJECT_HEADERS})
# Include the "src" directory for the main project
target_include_directories(intern_project PUBLIC src)

# Add the test executable
add_executable(intern_tests ${INTERN_PROJECT_TESTS} ${INTERN_PROJECT_HEADERS})
# Include the "src" directory for the tests
target_include_directories(intern_tests PUBLIC src)

# Link libraries for the main project
target_link_libraries(intern_project PRIVATE Python3::Python)
target_link_libraries(intern_project PRIVATE cpr::cpr nlohmann_json::nlohmann_json pybind11::pybind11)
target_link_libraries(intern_project PRIVATE ${Python3_LIBRARIES})

# Link libraries for the test executable
target_link_libraries(intern_tests PRIVATE Python3::Python)
target_link_libraries(intern_tests PRIVATE cpr::cpr nlohmann_json::nlohmann_json pybind11::pybind11)
target_link_libraries(intern_tests PRIVATE ${Python3_LIBRARIES})
target_link_libraries(intern_tests PRIVATE gtest::gtest)

# Add the pybind11 module
pybind11_add_module(intern src/cppsrc/main.cpp)
install(TARGETS intern DESTINATION intern_project)
target_link_libraries(intern PRIVATE cpr::cpr nlohmann_json::nlohmann_json)