CC=gcc
CFLAGS=-pthread -I.
DEPS = encript.h decypher.h manejoArchivos.h hilos.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

cript_t: cript_t.o 
	$(CC) -o cript_t cript_t.o -pthread