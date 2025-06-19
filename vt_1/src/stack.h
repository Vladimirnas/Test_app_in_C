// src/stack.h
#ifndef STACK_H
#define STACK_H

#define SUCCESS 0
#define FAIL 1

struct stack_node {
    int value;
    struct stack_node* next;
};

struct stack {
    struct stack_node* top;
};

struct stack* init();
int push(struct stack* s, int value);
int pop(struct stack* s, int* value);
void destroy(struct stack* s);

#endif // STACK_H
