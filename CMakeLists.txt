cmake_minimum_required (VERSION 3.11)
project (libhcl)

find_package (flex REQUIRED)
find_package (bison REQUIRED)

add_subdirectory (src)
#add_subdirectory (test)
