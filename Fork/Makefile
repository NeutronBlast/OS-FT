CC=gcc
CFLAGS=-I.
DEPS = encript.h decypher.h manejoArchivos.h slice.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

ordenArchivo-p: cript_p.o 
	$(CC) -o cript_p cript_p.o