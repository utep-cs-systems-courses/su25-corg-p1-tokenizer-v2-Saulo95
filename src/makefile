# Makefile for Tokenizer with History

CC = gcc
CFLAGS = -Wall -g
OBJ = uimain.o tokenizer.o history.o
TARGET = tokenizer

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

uimain.o: uimain.c tokenizer.h history.h
	$(CC) $(CFLAGS) -c uimain.c

tokenizer.o: tokenizer.c tokenizer.h
	$(CC) $(CFLAGS) -c tokenizer.c

history.o: history.c history.h
	$(CC) $(CFLAGS) -c history.c

clean:
	rm -f $(TARGET) *.o
