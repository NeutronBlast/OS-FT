CC=gcc
CFLAGS=-I.
DEPS = encript.h decypher.h manejoArchivos.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

cript: cript.o 
	$(CC) -o cript cript.o