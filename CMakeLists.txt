cmake_minimum_required(VERSION 3.21)

project(imp)

# SETUP VARIABLES:

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
set(CMAKE_INCLUDE_PATH ${PROJECT_SOURCE_DIR}/include)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/bin/${CMAKE_BUILD_TYPE}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/bin/${CMAKE_BUILD_TYPE}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/bin/${CMAKE_BUILD_TYPE}")
# set(SDL2_INCLUDE_DIR C:/SDL/include/SDL2) # is set by
# set(SDL2_LIB_DIR C:/SDL/lib)

# SETUP SDL2:

find_package(SDL2 REQUIRED)
include_directories(
        ${SDL2_INCLUDE_DIR}
        ${PROJECT_SOURCE_DIR}/include)
link_directories(${SDL2_LIB_DIR})


# INCLUDE FILES THAT SHOULD BE COMPILED:

add_executable(${PROJECT_NAME}
        src/main.cpp
        include/Lesson06.h
        src/Lesson06.cpp
        include/LessonBase2.h
        src/LessonBase2.cpp)


# LINK PROGRAM

target_link_libraries(${PROJECT_NAME} mingw32 SDL2main SDL2 SDL2_image)


# COPY OVER STATIC FILES

message(STATUS "Copying all assets to destination folder...")
file(COPY assets DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/bin/${CMAKE_BUILD_TYPE})

message(STATUS "Copying all dependencies to destination folder...")
file(GLOB PROJECT_DEPENDENCIES libs/*.dll)
foreach(Dependency IN LISTS PROJECT_DEPENDENCIES)
    file(COPY ${Dependency} DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/bin/${CMAKE_BUILD_TYPE})
endforeach()