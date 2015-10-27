cmake_minimum_required(VERSION 2.8)

set(HDR_LIST app/quick_union.h)
set(SRC_LIST app/quick_union.cpp
            app/main.cpp)

add_executable(app ${HDR_LIST} ${SRC_LIST})

add_subdirectory(tests)
