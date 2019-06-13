cmake_minimum_required (VERSION 3.11)
project (hcl)

find_package (flex REQUIRED)
find_package (bison REQUIRED)

add_subdirectory (src)
#add_subdirectory (test)
