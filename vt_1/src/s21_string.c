#include "s21_string.h"

int s21_strlen(const char *str) {
    int length = 0;
    if (str) {
        while (str[length] != '\0') {
            length++;
        }
    }
    return length;
}

int s21_strcmp(const char *str1, const char *str2) {
    if (!str1 || !str2){
        return 0;
    } 

    while (*str1 && *str2) {
        if (*str1 != *str2) {
            return (*str1 - *str2);
        }
        str1++;
        str2++;
    }
    return (*str1 - *str2);
}

char *s21_strcpy(char *dest, const char *src) {
    if (!dest || !src) return dest;

    char *original = dest;
    while (*src) {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
    return original;
}


