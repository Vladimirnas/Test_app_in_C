#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

// Функция для вывода информации о созданном узле
void print_node(t_btree *node) {
    if (node == NULL) {
        printf("Node is NULL\n");
    } else {
        printf("Node created: value = %d, left = %p, right = %p\n", 
               node->item, 
               (void*)node->left, 
               (void*)node->right);
    }
}

int main() {
    // Тест 1: Создание узла со значением 42
    t_btree *test_node1 = bstree_create_node(21);
    printf("Test 1: ");
    print_node(test_node1);
    
    // Тест 2: Создание узла со значением -10
    t_btree *test_node2 = bstree_create_node(42);
    printf("Test 2: ");
    print_node(test_node2);
    
    // Освобождаем выделенную память
    free(test_node1);
    free(test_node2);
    
    return 0;
}
