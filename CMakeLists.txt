cmake_minimum_required(VERSION 3.10)
project(calc)

enable_testing()

add_executable(calc main.c src/lexer.c src/ast.c src/parser.c src/evaluator.c src/repl.c)
target_include_directories(calc PRIVATE ${CMAKE_SOURCE_DIR}/src/include)

add_executable(tests tests/test_runner.c src/lexer.c src/ast.c src/parser.c src/evaluator.c src/repl.c)
target_include_directories(tests PRIVATE ${CMAKE_SOURCE_DIR}/src/include)
add_test(NAME ccalc_tests COMMAND tests)
