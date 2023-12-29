CC=g++
CFLAGS=-Wall -Wextra
SFILES=func.o
HFILES=func.h

all:rps

rps: $(SFILES) $(HFILES) main.cc
	$(CC) $(CFLAGS) -o rps $(SFILES) main.cc

clean:
	rm *.o rps 