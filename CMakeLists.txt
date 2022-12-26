cmake_minimum_required(VERSION 3.23)
project(untitled3 C)

set(CMAKE_C_STANDARD 23)
set(CMAKE_BUILD_TYPE Debug cashe)

add_executable(untitled3 main.c stack.h global.h queue.h deque.h baseQueue.h binaryTree.h)
