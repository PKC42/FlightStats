CC = g++
CFLAGS = -Wall -Werror -pedantic
OBJECTS = main.o flight.o
SFML = -lsfml-graphics -lsfml-window -lsfml-system
BOOST = -lboost_regex -lboost_date_time -lboost_unit_test_framework


all:FlightStats Test

Test:test.o flight.o compute.o
	$(CC) $(CFLAGS) -o Test test.o flight.o compute.o $(BOOST)

test.o:test.cpp compute.hpp
	$(CC) $(CFLAGS) -o test.o -c test.cpp

FlightStats:main.o flight.o compute.o
	$(CC) $(CFLAGS) -o FlightStats main.o flight.o compute.o $(BOOST)

main.o:main.cpp compute.hpp flight.hpp
	$(CC) $(CFLAGS) -o main.o -c main.cpp

flight.o:flight.cpp flight.hpp
	$(CC) $(CFLAGS) -o flight.o -c flight.cpp

compute.o:compute.cpp compute.hpp flight.hpp
	$(CC) $(CFLAGS) -o compute.o -c compute.cpp

clean:
	rm *.o FlightStats Test