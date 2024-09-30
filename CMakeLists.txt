cmake_minimum_required(VERSION 3.30.3)
project(TheWasteland VERSION 0.1.0)


# Defining C++ Language Standards
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED true)


# Defining the 32-bit/64-bit system
if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    set(OS_ARCHITECTURE 64)
else()
    set(OS_ARCHITECTURE 32)
endif()


# Defining output directory
set (OUTPUT_DIR "${CMAKE_SOURCE_DIR}/bin/${CMAKE_SYSTEM_NAME}${OS_ARCHITECTURE}/${CMAKE_BUILD_TYPE}")
set (CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${OUTPUT_DIR}/libs")
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY "${OUTPUT_DIR}")
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY "${OUTPUT_DIR}")


# Adding all the source files in project
file(GLOB_RECURSE CPP_FILES "${CMAKE_SOURCE_DIR}/src/*.cpp")


# Adding SDL2 in project
set(SDL2_DIR "C:/SDL/SDL2/cmake") 
set(SDL2_Image_DIR "C:/SDL/SDL2_image/cmake") 
find_package(SDL2 REQUIRED)
find_package(SDL2_Image REQUIRED)


# Adding executable
add_executable(${PROJECT_NAME} ${CPP_FILES})


# Include directories
include_directories(${PROJECT_NAME}  
    ${SDL2_INCLUDE_DIRS}
    ${CMAKE_SOURCE_DIR}/src
)


# Linking the libraries used in project
target_link_libraries(${PROJECT_NAME}
    SDL2::SDL2main
    SDL2::SDL2
    SDL2_image::SDL2_image
)