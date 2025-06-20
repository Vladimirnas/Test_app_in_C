SRC_1 = src/main_module_entry_point.c src/print_module.c
SRC_2 = src/main_module_entry_point.c src/print_module.c src/documentation_module.c
SRC_3 = src/bst_create_test.c src/bst.c
SRC_4 = src/bst_insert_test.c src/bst.c

CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11
BUILD_DIR = build

all: print_module documentation_module bst_create_test bst_insert_test

print_module:
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) $(SRC_1) -Dprint_module -o $(BUILD_DIR)/Quest_1

documentation_module:
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) $(SRC_2) -Ddocumentation_module -o $(BUILD_DIR)/Quest_2

bst_create_test:
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) $(SRC_3) -o $(BUILD_DIR)/Quest_3

bst_insert_test:
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) $(SRC_4) -o $(BUILD_DIR)/Quest_4

clean:
	rm -f src/*.o



