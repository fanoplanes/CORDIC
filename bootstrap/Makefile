all: pi.h constants.h

pi.h: pi
	./pi
	rm -f pi

constants.h: constants
	./constants
	rm -f constants

pi: atan.o pi.c
	gcc $^ -o pi

constants: sqrt.o atan.o constants.c
	gcc $^ -o constants

clean:
	rm -f *.o
