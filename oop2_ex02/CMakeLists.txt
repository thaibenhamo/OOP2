cmake_minimum_required (VERSION 3.26)

project (oop2_ex02)
set (MY_AUTHORS "Thai_Ben_Hamo")

include (cmake/CompilerSettings.cmake)

add_executable (${CMAKE_PROJECT_NAME})

target_compile_options(${CMAKE_PROJECT_NAME} PRIVATE $<$<CONFIG:DEBUG>:-fsanitize=address>)
target_link_options(${CMAKE_PROJECT_NAME} PRIVATE $<$<CONFIG:DEBUG>:-fsanitize=address>)

add_subdirectory (include)
add_subdirectory (src)

include (cmake/Zip.cmake)
