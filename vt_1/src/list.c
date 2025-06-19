// src/list.c
#include <stdlib.h>
#include "list.h"

struct node* init(struct door* door) {
    if (!door) return NULL;
    struct node* new_node = malloc(sizeof(struct node));
    if (!new_node) return NULL;
    new_node->data = *door;
    new_node->next = NULL;
    return new_node;
}

struct node* add_door(struct node* elem, struct door* door) {
    if (!elem || !door) return NULL;
    struct node* new_node = malloc(sizeof(struct node));
    if (!new_node) return NULL;
    new_node->data = *door;
    new_node->next = elem->next;
    elem->next = new_node;
    return new_node;
}

struct node* find_door(int door_id, struct node* root) {
    struct node* current = root;
    while (current) {
        if (current->data.id == door_id) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

struct node* remove_door(struct node* elem, struct node* root) {
    if (!elem || !root) return root;

    if (elem == root) {
        struct node* new_root = root->next;
        free(root);
        return new_root;
    }

    struct node* prev = root;
    while (prev && prev->next != elem) {
        prev = prev->next;
    }

    if (prev && prev->next == elem) {
        prev->next = elem->next;
        free(elem);
    }

    return root;
}

void destroy(struct node* root) {
    while (root) {
        struct node* temp = root;
        root = root->next;
        free(temp);
    }
}
