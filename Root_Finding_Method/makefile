CC = g++
LINK = g++

root_finding_method: main.o util.o calculations.o
	$(LINK) main.o util.o calculations.o -o root_finding_method

main.o: main.cpp
	$(CC) -c main.cpp

util.o: util.cpp
	$(CC) -c util.cpp

calculations.o: calculations.cpp
	$(CC) -c calculations.cpp
