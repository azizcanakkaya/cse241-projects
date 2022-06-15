CFLAGS = --std=c++11

CC = g++

ALL = main.o creature.o human.o elf.o demon.o balrog.o cyberdemon.o

output: $(ALL)
	$(CC) $(CFLAGS) $(ALL) -o output
	./output

main.o: main.cpp
	$(CC) -c main.cpp

creature.o: creature.h
	$(CC) -c creature.cpp

balrog.o: balrog.h
	$(CC) -c balrog.cpp

cyberdemon.o: cyberdemon.h
	$(CC) -c cyberdemon.cpp

demon.o: demon.h
	$(CC) -c demon.cpp

elf.o: elf.h
	$(CC) -c elf.cpp

human.o: human.h
	$(CC) -c human.cpp

clean:
	rm *.o output
