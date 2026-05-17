cordic: constants.h pi.h cordic.c
	gcc -c -o cordic.o cordic.c

constants.h pi.h:
	make -C bootstrap
	mv bootstrap/pi.h .
	mv bootstrap/constants.h .

clean:
	make -C bootstrap clean
	rm -f *.o
