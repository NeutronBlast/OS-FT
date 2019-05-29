CC=gcc
CFLAGS=-I.
DEPS = test.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

ordenArchivo: ordenArchivo.o 
	$(CC) -o ordenArchivo ordenArchivo.o