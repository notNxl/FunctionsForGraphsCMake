cmake_minimum_required (VERSION 3.8)

project ("FunctionsForGraphsCMake")

add_executable (main "main.cpp")

target_link_libraries(main functions)
add_subdirectory(include)
add_subdirectory(src)
