cmake_minimum_required(VERSION 3.15)
project(21f_flight_planner)

set(CMAKE_CXX_STANDARD 14)

configure_file(data/sample01-flight-data.txt data/sample01-flight-data.txt COPYONLY)
configure_file(data/sample01-req-flights.txt data/sample01-req-flights.txt COPYONLY)

add_executable(21f_flight_planner main.cpp catch_setup.cpp sample_tests.cpp LinkedList.h DSStack.h OriginCity.cpp OriginCity.h DestinationCity.cpp DestinationCity.h AdjacencyList.cpp AdjacencyList.h Control.cpp Control.h Itinerary.cpp Itinerary.h Flight.cpp Flight.h Backtracking.cpp Backtracking.h Request.cpp Request.h)
