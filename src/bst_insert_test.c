#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

// Функция сравнения для вставки в дерево
int compare_ints(int a, int b) {
    return a - b;
}

// Функция для вывода узла
void print_node(t_btree *node) {
    if (node == NULL) {
        printf("Node is NULL\n");
    } else {
        printf("Node: value = %d, left = %p, right = %p\n", 
               node->item, 
               (void*)node->left, 
               (void*)node->right);
    }
}

// Функция для рекурсивного вывода структуры дерева
void print_tree(t_btree *root, int level) {
    if (root == NULL) {
        return;
    }
    
    // Увеличиваем отступ для уровня
    for (int i = 0; i < level; i++) {
        printf("    ");
    }
    
    // Выводим значение текущего узла
    printf("|-- %d\n", root->item);
    
    // Рекурсивно выводим левое и правое поддерево
    if (root->left || root->right) {
        if (root->left) {
            print_tree(root->left, level + 1);
        } else {
            // Если левого поддерева нет, но есть правое - показываем пустое место
            for (int i = 0; i < level + 1; i++) {
                printf("    ");
            }
            printf("|-- NULL\n");
        }
        
        if (root->right) {
            print_tree(root->right, level + 1);
        }
    }
}



int main() {
    // Тест 1: Создание дерева и вставка нескольких узлов
    printf("Тест 1: Создание дерева с корнем 10 и вставка узлов\n");
    t_btree *root1 = bstree_create_node(10);
    
    printf("Корень дерева: ");
    print_node(root1);
    
    bstree_insert(root1, 5, compare_ints);
    bstree_insert(root1, 15, compare_ints);
    bstree_insert(root1, 3, compare_ints);
    bstree_insert(root1, 7, compare_ints);
    
    printf("\nСтруктура дерева после вставки:\n");
    printf("Корень: ");
    print_node(root1);
    printf("Левый потомок корня: ");
    print_node(root1->left);
    printf("Правый потомок корня: ");
    print_node(root1->right);
    printf("Левый потомок левого потомка корня: ");
    print_node(root1->left->left);
    printf("Правый потомок левого потомка корня: ");
    print_node(root1->left->right);
    
    // Тест 2: Еще одно дерево с другими значениями
    printf("\nТест 2: Создание дерева с корнем 100 и вставка узлов\n");
    t_btree *root2 = bstree_create_node(100);
    
    printf("Корень дерева: ");
    print_node(root2);
    
    bstree_insert(root2, 50, compare_ints);
    bstree_insert(root2, 150, compare_ints);
    bstree_insert(root2, 25, compare_ints);
    bstree_insert(root2, 75, compare_ints);
    
    printf("\nСтруктура дерева после вставки:\n");
    printf("Корень: ");
    print_node(root2);
    printf("Левый потомок корня: ");
    print_node(root2->left);
    printf("Правый потомок корня: ");
    print_node(root2->right);
    printf("Левый потомок левого потомка корня: ");
    print_node(root2->left->left);
    printf("Правый потомок левого потомка корня: ");
    print_node(root2->left->right);
    
    // Освобождаем память (для простоты освобождаем только корни)
    // В реальном приложении нужно было бы освободить все узлы дерева
    free(root1);
    free(root2);
    
    return 0;
}
