#ifndef BST_H
#define BST_H

// Структура узла бинарного дерева поиска
typedef struct s_btree {
    struct s_btree *left;
    struct s_btree *right;
    int item;
} t_btree;

// Функция для создания узла дерева
t_btree *bstree_create_node(int item);

// Функция вставки узла в дерево
void bstree_insert(t_btree *root, int item, int (*cmpf)(int, int));



#endif // BST_H
