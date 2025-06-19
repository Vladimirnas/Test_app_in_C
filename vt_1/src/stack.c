// src/stack.c
#include <stdlib.h>
#include "stack.h"

struct stack* init() {
    struct stack* s = malloc(sizeof(struct stack));
    if (!s) return NULL;
    s->top = NULL;
    return s;
}

int push(struct stack* s, int value) {
    if (!s) return FAIL;

    struct stack_node* new_node = malloc(sizeof(struct stack_node));
    if (!new_node) return FAIL;

    new_node->value = value;
    new_node->next = s->top;
    s->top = new_node;
    return SUCCESS;
}

int pop(struct stack* s, int* value) {
    if (!s || !s->top || !value) return FAIL;

    struct stack_node* temp = s->top;
    *value = temp->value;
    s->top = temp->next;
    free(temp);
    return SUCCESS;
}

void destroy(struct stack* s) {
    if (!s) return;

    struct stack_node* current = s->top;
    while (current) {
        struct stack_node* temp = current;
        current = current->next;
        free(temp);
    }
    free(s);
}
