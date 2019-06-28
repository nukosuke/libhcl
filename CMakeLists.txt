cmake_minimum_required (VERSION 3.11)
project (hcl)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

find_package (FLEX REQUIRED)
find_package (BISON REQUIRED)

add_subdirectory (src)

enable_testing ()
add_subdirectory (test)
