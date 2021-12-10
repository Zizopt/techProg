cmake_minimum_required(VERSION 3.5)


project(mat)


file(GLOB CPPSS "*.cpp")
add_library(mat STATIC ${CPPSS})


add_executable(GTest ../GTmain.cpp ../dopF.cpp)
target_link_libraries(GTest mat)
target_link_libraries(GTest gtest)