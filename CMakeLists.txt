cmake_minimum_required(VERSION 3.10)

project(AirTraffic)



set(CMAKE_CXX_STANDARD 17)



include_directories(include)


file(GLOB SOURCES "src/*.cpp")


#SET(GCC_COMPILE_FLAGS "-lpthread -lncurses")

#add_definitions(${GCC_COMPILE_FLAGS})


#find_package(Curses REQUIRED)

#include_directories(${CURSES_INCLUDE_DIR})



add_executable(program src/main.cpp src/plane.cpp include/plane.h src/airfield.cpp include/airfield.h src/timetable.cpp include/timetable.h src/PCH.cpp include/PCH.h)



#target_link_libraries(snake ${CURSES_LIBRARIES})

