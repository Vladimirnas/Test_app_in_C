
#include <stdio.h>
#include "s21_string.h"

void s21_strlen_test() {

    const char *tests[] = {
        "Hello, world!",   
        "",               
        NULL,            
        "a",            
    };

    int expected[] = {14, 0, 0, 1};

    for (int i = 0; i < 4; ++i) {
        int result = s21_strlen(tests[i]);
    
        printf("  Input: %s\n", tests[i] ? tests[i] : "NULL");
        printf("  Output: %d\n", result);
        printf("  Result: %s\n\n", (result == expected[i]) ? "SUCCESS" : "FAIL");
    }
}



void s21_strcmp_test() {
    const char *test1[] = {
        "abc", "abc",
        "abc", "abd",
        "", "",
        "abc", "r",
        0, "abc",
        "abc", 0
    };

    int expected[] = {
        0,   
        -1,   
        0,    
        '0', 
        0,    
        0    
    };

    for (int i = 0; i < 6; ++i) {
        const char *s1 = test1[i * 2];
        const char *s2 = test1[i * 2 + 1];

        int res = s21_strcmp(s1, s2);
        int exp = expected[i];
        int pass = (exp == 0) ? (res == 0) : ((exp > 0 && res > 0) || (exp < 0 && res < 0));
        
        
    
        printf("s1 = %s, s2 = %s\n", s1 ? s1 : "NULL", s2 ? s2 : "NULL");
        printf("%d\n", res);
        printf("%s\n\n", pass ? "SUCCESS" : "FAIL");
    }
}


void s21_strcpy_test() {
    const char *sources[] = {
        "Hello, world!",
        "234234",
        NULL
    };

    char expected[][50] = {
        "Hello, world!",
        "",
        "" 
    };

    for (int i = 0; i < 3; ++i) {
        char dest[50] = "initial_data";
        char *result = s21_strcpy(dest, sources[i]);

        printf("%s\n", result ? result : "NULL");
        int pass = (sources[i] == NULL) ? (result == dest) : (s21_strcmp(result, expected[i]) == 0);
        printf("%s\n", pass ? "SUCCESS" : "FAIL");
    }
}


void s21_strcat_test() {
    printf("Quest_4\n");

    char dest[5][100] = {
        "Hello, ",
        "",
        "Data",
        "",
        "Con"
    };

    const char *src[] = {
        "world!",
        "Test",
        "rere",
        "",
        "test"
    };

    const char *expected[] = {
        "Hello, world!",
        "Test",
        "Datarere",
        "",
        "Content"
    };

    for (int i = 0; i < 5; ++i) {
        char original_dest[100];
        int j = 0;
        while (dest[i][j] != '\0' && j < 99) {
            original_dest[j] = dest[i][j];
            j++;
        }
        original_dest[j] = '\0';

        char *result = s21_strcat(dest[i], src[i]);

        printf("Test %d:\n", i + 1);
        printf("%s %s\n", original_dest, src[i]);
        printf("%s\n", result);

        int pass = (result && expected[i]) ? (s21_strcmp(result, expected[i]) == 0) : (result == expected[i]);
        printf("%s\n\n", pass ? "SUCCESS" : "FAIL");
    }
}

 
int main() {
    #ifdef STRLEN_TESTS
    s21_strlen_test();
    #endif
    #ifdef STRCMP_TESTS
    s21_strcmp_test();
    #endif
    #ifdef STRCPY_TESTS
    s21_strcpy_test();
    #endif

    #ifdef STRCAT_TESTS
    s21_strcat_test();
    #endif
    return 0;
}
