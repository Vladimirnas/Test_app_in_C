CC = gcc
CFLAGS = -Wall -Wextra -std=c11
SRC = s21_string.c s21_string_test.c
OBJ = $(SRC:.c=.o)
TARGET = ../build/Quest_1

strlen_tests: $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

clean:
	rm -f $(OBJ) $(TARGET)