cmake_minimum_required(VERSION 3.14)
project(ArquiCompu C)

set(CMAKE_C_STANDARD 99)

add_executable(ArquiCompu main.c Caderita.h delay.h potencia.h EasyPIO.h KBHIT.h)