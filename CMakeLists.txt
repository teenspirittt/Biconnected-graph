cmake_minimum_required(VERSION 3.14)
project(Biconnected-Graph)
set(CMAKE_CXX_STANDARD 14)
add_executable(Biconnected-Graph
        src/main.cpp
        src/Graph.cpp
        src/Graph.h
        src/Edge.h
        src/Vertex.h
        src/OutEdgeIterator.h
        src/EdgeIterator.h
        src/GraphForm.h
        src/GraphMatrix.h
        src/GraphList.h
        src/menu.h)

