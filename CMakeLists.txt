cmake_minimum_required(VERSION 3.10)
project(calc)
add_executable(calc main.c src/lexer.c src/ast.c src/parser.c src/evaluator.c)


target_include_directories(calc PRIVATE ${CMAKE_SOURCE_DIR}/src/include)
