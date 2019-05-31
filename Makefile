CC=gcc
CFLAGS=-I.
DEPS = manejoArchivos.h procesosintermedios.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

ordenArchivo-p: cript_p.o 
	$(CC) -o cript_p cript_p.o