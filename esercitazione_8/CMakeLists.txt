cmake_minimum_required(VERSION 3.20)
project(esercitazione8)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wshadow -Werror=vla")

## Creo i target per gli eseguibili che effettueranno i test unitari
add_executable(test1 main.cpp)
add_test(NAME test_tutto COMMAND test1)
enable_testing()
