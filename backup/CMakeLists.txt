cmake_minimum_required(VERSION 3.10)
project(MazeGenerator)

set(CMAKE_CXX_STANDARD 17)
find_package(OpenCV REQUIRED)

if (MSVC)
    add_compile_definitions(_USE_MATH_DEFINES)
endif()

add_executable(MazeGenerator
        main.cpp
        GenMaze.cpp
        GenMaze.hpp
        BicycleTemp.cpp
        BicycleTemp.hpp
)

target_include_directories(MazeGenerator PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${OpenCV_INCLUDE_DIRS}
)

target_link_libraries(MazeGenerator PRIVATE ${OpenCV_LIBS})
