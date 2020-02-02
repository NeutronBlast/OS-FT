CC = gcc
CFLAGS = -Wall
LDFLAGS =
OBJFILES = encript.o decypher.o manejoArchivos.o slice.o cript_p.o
TARGET = cript_p
all = $(TARGET)

$(TARGET): $(OBJFILES)
		$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES) $(LDFLAGS)

clean:
		rm -f $(OBJFILES) $(TARGET) *~
