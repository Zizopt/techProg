cmake_minimum_required(VERSION 3.5)

project(KM)

file(GLOB CPPS "*.cpp")

add_executable(KM ${CPPS})
add_subdirectory(mat)

target_link_libraries(KM mat)

target_include_directories(KM PUBLIC "../boost_1_77_0" )
target_link_directories(KM PUBLIC "../boost_1_77_0/stage/lib")


