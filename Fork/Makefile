CC=gcc
CFLAGS=-I.
DEPS = manejoArchivos.h procesosintermedios.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

ordenArchivo-p: ordenArchivo-p.o 
	$(CC) -o ordenArchivo-p ordenArchivo-p.o