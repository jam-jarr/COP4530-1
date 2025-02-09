cmake_minimum_required(VERSION 3.29)
project(COP4530)

set(CMAKE_CXX_STANDARD 11)

set (SOURCES
        "assignments/PP1(inOrderList)/IntDList.cpp"
        "assignments/PP1(inOrderList)/DNode.cpp"
        "assignments/PP1(inOrderList)/intDList_test.cpp"

)
set (HEADERS
        "assignments/PP1(inOrderList)/DNode.hpp"
        "assignments/PP1(inOrderList)/IntDList.hpp"
)
add_executable(COP4530 ${SOURCES} ${HEADERS})
