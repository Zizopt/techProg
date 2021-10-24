cmake_minimum_required(VERSION 3.5)

project(mat)

file(GLOB CPPSS "*.cpp")
add_library(mat STATIC ${CPPSS})