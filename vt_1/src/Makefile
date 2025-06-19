CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11
BUILD = ../build

DOOR_EXEC = $(BUILD)/Quest_1
LIST_EXEC = $(BUILD)/Quest_2
STACK_EXEC = $(BUILD)/Quest_3

DOOR_SRC = dmanager_module.c
DOOR_HEADERS = door_struct.h

LIST_SRC = list.c list_test.c
LIST_HEADERS = list.h door_struct.h

STACK_SRC = stack.c stack_test.c
STACK_HEADERS = stack.h

all: door_struct list_test stack_test

door_struct: $(DOOR_SRC) $(DOOR_HEADERS)
	@mkdir -p $(BUILD)
	$(CC) $(CFLAGS) -o $(DOOR_EXEC) $(DOOR_SRC)

list_test: $(LIST_SRC) $(LIST_HEADERS)
	@mkdir -p $(BUILD)
	$(CC) $(CFLAGS) -o $(LIST_EXEC) $(LIST_SRC)

stack_test: $(STACK_SRC) $(STACK_HEADERS)
	@mkdir -p $(BUILD)
	$(CC) $(CFLAGS) -o $(STACK_EXEC) $(STACK_SRC)

clean:
	rm -rf $(BUILD)
