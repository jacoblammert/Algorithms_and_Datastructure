cmake_minimum_required(VERSION 3.15)
project(algorithms_and_datastructure)

set(CMAKE_CXX_STANDARD 14)

add_executable(algorithms_and_datastructure Ass1/main.cpp Ass1/Sort.cpp)
add_executable(algorithms_and_datastructure2 Ass2/main.cpp Ass2/BinaryTree.cpp)
add_executable(algorithms_and_datastructure3 Ass3/main.cpp Ass3/Node.cpp Ass3/MinHeapNode.cpp Ass3/MinHeap.cpp Ass3/Graph.cpp)
add_executable(algorithms_and_datastructure4 Ass4/main.cpp Ass4/closestPoints.cpp Ass4/point.cpp)