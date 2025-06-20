#include <stdlib.h>
#include "bst.h"

// Функция создания узла бинарного дерева поиска
t_btree *bstree_create_node(int item) {

    t_btree *node = (t_btree *)malloc(sizeof(t_btree));
    

    if (node != NULL) {

        node->item = item;
    
        node->left = NULL;
        node->right = NULL;
    }
    
    return node;
}

// Функция вставки узла в бинарное дерево поиска
void bstree_insert(t_btree *root, int item, int (*cmpf)(int, int)) {
    // Проверка на NULL
    if (root == NULL) {
        return;
    }
    
    // Сравниваем значение вставляемого элемента с текущим узлом
    int comparison = cmpf(item, root->item);
    
    if (comparison < 0) {
        // Если значение меньше, идем в левое поддерево
        if (root->left == NULL) {
            // Если левого поддерева нет, создаем новый узел
            root->left = bstree_create_node(item);
        } else {
            // Иначе рекурсивно вызываем вставку для левого поддерева
            bstree_insert(root->left, item, cmpf);
        }
    } else if (comparison >= 0) {
        // Если значение больше или равно, идем в правое поддерево
        if (root->right == NULL) {
            // Если правого поддерева нет, создаем новый узел
            root->right = bstree_create_node(item);
        } else {
            // Иначе рекурсивно вызываем вставку для правого поддерева
            bstree_insert(root->right, item, cmpf);
        }
    }
}
