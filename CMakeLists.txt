cmake_minimum_required(VERSION 3.25)
project(Proj2)

set(CMAKE_CXX_STANDARD 17)

add_executable(Proj2 main.cpp src/AuxMain.h src/AuxMain.cpp src/Graph.h src/Graph.cpp src/Functions.h src/Functions.cpp src/Node.cpp src/Node.h src/UnionFind.cpp src/UnionFind.h)
