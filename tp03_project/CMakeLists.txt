cmake_minimum_required(VERSION 4.3)
project(tp03_project C)

set(CMAKE_C_STANDARD 23)

add_executable(tp03_project main.c
        lexer.h
        lexer.c
        parseur.h
        parseur.c
        evaluation.c
        evaluation.h)
