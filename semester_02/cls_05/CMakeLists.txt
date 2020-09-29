cmake_minimum_required (VERSION 3.8)

project(classwork-05)

set(CMAKE_CXX_STANDARD 17)

if(MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /WX") # CMake already contains W3 in its flags
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror")
endif()

include_directories(src)

#add_executable(task-1-test src/task_1/test.cpp)
#add_executable(task-2-test src/task_2_3_4/test_2.cpp)
#add_executable(task-3-test src/task_2_3_4/test_3.cpp)
#add_executable(task-4-test src/task_2_3_4/test_4.cpp)
