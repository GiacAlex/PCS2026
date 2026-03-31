
cmake_minimum_required(VERSION 3.20)

project(Esercitazione1) 

# In 
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE CXX FLAGS "${CMAKE CXX FLAGS} -Wall -Wshadow -Werror=vla")


add_executable(ese1 prova1.cpp)
add_executable(ese2 es2.cpp)
add_executable(ese3 sort.cpp)
