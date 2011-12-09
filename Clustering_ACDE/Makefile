CC = g++     # name of the compiler
CFLAGS = -O3 # optimization flags

program: main.o DE.o POP.o input.o 
	$(CC) $(CFLAGS) -o program main.o DE.o  POP.o input.o
    
#program: main.o  POP.o input.o 
#	$(CC) $(CFLAGS) -o program POP.o input.o main.o


main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

DE.o: DE.cpp
	$(CC) $(CFLAGS) -c DE.cpp

POP.o: POP.cpp
	$(CC) $(CFLAGS) -c POP.cpp

input.o: input.cpp 
	$(CC) $(CFLAGS) -c input.cpp

clean:
	rm -f *.o *.bmp program

debug:  
	g++ -ggdb -o program main.cpp DE.cpp POP.cpp input.cpp 
