cmake_minimum_required(VERSION 3.29)
project(ProyectoFinal)

set(CMAKE_CXX_STANDARD 20)

add_executable(ProyectoFinal main.cpp
        Empresa.cpp
        Empresa.h
        Proyecto.cpp
        Proyecto.h
        Designer.cpp
        Designer.h
        Developer.cpp
        Developer.h)
