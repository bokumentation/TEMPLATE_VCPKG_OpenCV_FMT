cmake_minimum_required(VERSION 3.10)
cmake_policy(SET CMP0074 NEW)

project(My_Apps VERSION 1.0.0 LANGUAGES CXX) 

# Set CMAKE standard
set(CMAKE_CXX_STANDARD 17) 
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Find VCPKG libraries
find_package(fmt CONFIG REQUIRED)
find_package(OpenCV CONFIG REQUIRED)
if(NOT OpenCV_FOUND)
    message(FATAL_ERROR "OpenCV not found. Check Vcpkg/System install.")
endif()

# --- Define Executable and Link Libraries ---
add_executable(${PROJECT_NAME} src/main.cpp)

# Link OpenCV headers to target privately
target_include_directories(${PROJECT_NAME} PRIVATE ${OpenCV_INCLUDE_DIRS})

# Project's internal header
target_include_directories(${PROJECT_NAME} PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/src/include
)

target_link_libraries(${PROJECT_NAME} 
    PRIVATE 
        ${OpenCV_LIBS} 
        fmt::fmt
)

