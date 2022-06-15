CFLAGS = --std=c++11

CC = g++

ALL = main.o world.o ant.o p_ant.o doodlebug.o organism.o

output: $(ALL)
	$(CC) $(ALL) -o output
	./output

main.o: main.cpp
	$(CC) -c main.cpp

ant.o: ant.h
	$(CC) -c ant.cpp

p_ant.o: p_ant.h
	$(CC) -c p_ant.cpp

world.o: world.h
	$(CC) -c world.cpp

doodlebug.o: doodlebug.h
	$(CC) -c doodlebug.cpp

organism.o: organism.h
	$(CC) -c organism.cpp

clean:
	rm *.o output
