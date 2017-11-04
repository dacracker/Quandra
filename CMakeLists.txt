cmake_minimum_required(VERSION 3.0.0 FATAL_ERROR)

project(Quandra C)

# We want to mark all debug binaries with a d suffix
set(CMAKE_DEBUG_POSTFIX "d")

# We want to put all binaries in the same output dir	   
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

# And we want all out libs to be in the same folderas the executables
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

include_directories("${PROJECT_BINARY_DIR}")

add_subdirectory(src/quandra)
#add_subdirectory(src/qeditor)
