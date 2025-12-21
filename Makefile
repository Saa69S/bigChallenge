CC = gcc
CFLAGS = -Wall -g
OBJ = main.o fungsi.o
TARGET = sort_program

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

main.o: main.c header.h
	$(CC) $(CFLAGS) -c main.c

select.o: fungsi.c header.h
	$(CC) $(CFLAGS) -c fungsi.c

clean:
	rm -f $(OBJ) $(TARGET)