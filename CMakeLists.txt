cmake_minimum_required(VERSION 3.9)
project(katana)

set(CMAKE_CXX_STANDARD 14)

set(KATANA_SOURCES
        )

add_executable(Katana
        main.cpp
        ${KATANA_SOURCES}
        )