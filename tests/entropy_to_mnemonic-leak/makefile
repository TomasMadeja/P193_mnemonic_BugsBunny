CC = gcc
TARGET = leak
SOURCES = ../../src/mnemonics.c ../../src/errorcodes.c ../../src/dictionary.c
CFLAGS = -g -lcrypto

leak: main.o
	$(CC) $(SOURCES) $(CFLAGS) $^ -o $@

clean:
	-rm *.o $(TARGET)
