cmake_minimum_required(VERSION 3.5)


set(gtest_force_shared_crt ON CACHE BOOL "Always use msvcrt.dll" FORCE)
project(KM_progect)
add_subdirectory(mat)
add_subdirectory(gt)

if(NOTTEST)
	add_executable(KM main.cpp dopF.cpp)
	target_link_libraries(KM mat)
	target_include_directories(KM PUBLIC "./boost_1_77_0" )
	target_link_directories(KM PUBLIC "./boost_1_77_0/stage/lib")
endif()

