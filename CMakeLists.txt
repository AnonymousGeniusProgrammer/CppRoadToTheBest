CMAKE_MINIMUM_REQUIRED(VERSION 3.15 FATAL_ERROR)

Project("CppRoadToTheBest")

SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin" CACHE PATH "Runtime directory" FORCE)
add_subdirectory(src)