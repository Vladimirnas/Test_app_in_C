#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "door_struct.h"

static int test_add_door() {
    struct door d1 = {1, 0};
    struct door d2 = {2, 0};

    struct node* root = init(&d1);
    if (!root) return FAIL;

    const struct node* added = add_door(root, &d2);
    if (!added) {
        destroy(root);
        return FAIL;
    }

    if (root->next != added || added->data.id != 2) {
        destroy(root);
        return FAIL;
    }

    destroy(root);
    return SUCCESS;
}

static int test_remove_door() {
    struct door d1 = {1, 0};
    struct door d2 = {2, 0};

    struct node* root = init(&d1);
    if (!root) return FAIL;

    const struct node* added = add_door(root, &d2);
    if (!added) {
        destroy(root);
        return FAIL;
    }

    root = remove_door((struct node*)added, root);
    if (root->next != NULL) {
        destroy(root);
        return FAIL;
    }

    destroy(root);
    return SUCCESS;
}

static int test_find_door() {
    struct door d1 = {10, 1};
    struct door d2 = {20, 0};

    struct node* root = init(&d1);
    if (!root) return FAIL;

    const struct node* added = add_door(root, &d2);
    if (!added) {
        destroy(root);
        return FAIL;
    }

    const struct node* found = find_door(20, root);
    if (!found || found->data.id != 20) {
        destroy(root);
        return FAIL;
    }

    destroy(root);
    return SUCCESS;
}

int main() {
    int result = SUCCESS;

    if (test_add_door() != SUCCESS) {
        printf("test_add_door FAILED\n");
        result = FAIL;
    } else {
        printf("test_add_door PASSED\n");
    }

    if (test_remove_door() != SUCCESS) {
        printf("test_remove_door FAILED\n");
        result = FAIL;
    } else {
        printf("test_remove_door PASSED\n");
    }

    if (test_find_door() != SUCCESS) {
       
        result = FAIL;
    } else {
       
    }

    return result;
}
