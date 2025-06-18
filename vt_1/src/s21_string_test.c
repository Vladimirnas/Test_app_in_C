
// #include <stdio.h>
// #include "s21_string.h"

// void s21_strlen_test() {
//     const char *tests[] = {
//         "Hello, world!",   
//         "",               
//         NULL,            
//         "a",            
//     };

//     int expected[] = {14, 0, 0, 1};

//     for (int i = 0; i < 4; ++i) {
//         int result = s21_strlen(tests[i]);
//         printf("Test %d:\n", i + 1);
//         printf("  Input: %s\n", tests[i] ? tests[i] : "NULL");
//         printf("  Output: %d\n", result);
//         printf("  Expected: %d\n", expected[i]);
//         printf("  Result: %s\n\n", (result == expected[i]) ? "SUCCESS" : "FAIL");
//     }
// }

// int main() {
//     s21_strlen_test();
//     return 0;
// }


#include <stdio.h>
#include "s21_string.h"

void s21_strlen_test() {
    const char *tests[] = {
        "a",                                            
        "",                                             
        0,                                         
        "Hello  ",                                
        "HELLO, WORLD!",                               
        "test", 
        "         "                 
    };

    int expected[] = {1, 0, 0, 13, 13, 66, 24};

    for (int i = 0; i < 7; ++i) {
        int result = s21_strlen(tests[i]);
        printf("%d\n", result);
        printf("%s\n", (result == expected[i]) ? "SUCCESS" : "FAIL");
    }


    for (int i = 0; i < 7; ++i) {
        if (tests[i]) {
            printf("%s\n", tests[i]);
        } else {
            printf("NULL\n");
        }
    }
}
 
int main() {
    s21_strlen_test();
    return 0;
}
