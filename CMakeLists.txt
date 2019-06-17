cmake_minimum_required (VERSION 3.11)
project (hcl)

find_package (FLEX REQUIRED)
find_package (BISON REQUIRED)

add_subdirectory (src)
add_subdirectory (test)
