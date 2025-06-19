// src/stack_test.c
#include <stdio.h>
#include "stack.h"

int test_push() {
    struct stack* s = init();
    if (!s) return FAIL;

    if (push(s, 10) != SUCCESS || !s->top || s->top->value != 10) {
        destroy(s);
        return FAIL;
    }

    destroy(s);
    return SUCCESS;
}

int test_pop() {
    struct stack* s = init();
    if (!s) return FAIL;

    push(s, 20);
    int value = 0;
    if (pop(s, &value) != SUCCESS || value != 20 || s->top != NULL) {
        destroy(s);
        return FAIL;
    }

    destroy(s);
    return SUCCESS;
}

int main() {
    int result = SUCCESS;

    if (test_push() != SUCCESS) {
        printf("test_push FAILED\n");
        result = FAIL;
    } else {
        printf("test_push PASSED\n");
    }

    if (test_pop() != SUCCESS) {
        printf("test_pop FAILED\n");
        result = FAIL;
    } else {
        printf("test_pop PASSED\n");
    }

    return result;
}
