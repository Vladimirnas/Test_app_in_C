CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11
BUILD_DIR = ../build
SRC_IMPL = s21_string.c
SRC_TEST = s21_string_test.c

TARGET_STRLEN = $(BUILD_DIR)/Quest_1
TARGET_STRCMP = $(BUILD_DIR)/Quest_2
TARGET_STRCPY = $(BUILD_DIR)/Quest_3

all: strlen_tests strcmp_tests strcpy_tests

strlen_tests: $(SRC_IMPL) $(SRC_TEST)
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -DSTRLEN_TESTS -o $(TARGET_STRLEN) $(SRC_IMPL) $(SRC_TEST)

strcmp_tests: $(SRC_IMPL) $(SRC_TEST)
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -DSTRCMP_TESTS -o $(TARGET_STRCMP) $(SRC_IMPL) $(SRC_TEST)

strcpy_tests: $(SRC_IMPL) $(SRC_TEST)
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -DSTRCPY_TESTS -o $(TARGET_STRCPY) $(SRC_IMPL) $(SRC_TEST)

clean:
	rm -rf $(BUILD_DIR)
