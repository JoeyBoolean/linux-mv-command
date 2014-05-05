# Makefile for program 3
# remove `program3.h' below if you do not need this header file.

CC=gcc -Wall

all  : my_mv

my_mv  : error_functions.o program3.o
	$(CC) -o my_mv error_functions.o program3.o

error_functions.o : error_functions.h ename.c.inc tlpi_hdr.h get_num.h  error_functions.c
	$(CC) -c error_functions.c

program3.o : tlpi_hdr.h get_num.h error_functions.h program3.c
	$(CC) -c program3.c

clean  :
	rm -f  error_functions.o program3.o core my_mv

tidy  :
	rm -f  error_functions.o program3.o core
