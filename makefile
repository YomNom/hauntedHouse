hauntedCarRide : hauntedCarRide.o hauntedHouse.o
	g++ -pthread -o hauntedCarRide hauntedCarRide.o hauntedHouse.o

hauntedCarRide.o : hauntedCarRide.cpp hauntedCarRide.h
	g++ -c hauntedCarRide.cpp

hauntedHouse.o : hauntedHouse.cpp hauntedCarRide.h
	g++ -c hauntedHouse.cpp
