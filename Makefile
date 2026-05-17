cordic.o: constants.h pi.h cordic.c
	gcc -c -o cordic.o cordic.c

constants.h pi.h:
	make -C bootstrap
	mv bootstrap/pi.h .
	mv bootstrap/constants.h .

example: cordic.o example.c
	gcc example.c cordic.o -lm -o example

clean:
	make -C bootstrap clean
	rm -f *.o
	rm -f example

scour:
	make clean
	rm -f constants.h pi.h
