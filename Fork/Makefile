CC=gcc
CFLAGS=-I.
DEPS = test.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

fork: fork.o 
	$(CC) -o fork fork.o