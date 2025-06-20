#include <stdio.h>
#include <stdlib.h>

#include "print_module.h"
#include "documentation_module.h"

#define DOCS_COUNT 4

int main()
{
    #ifdef print_module
    print_log(print_char, Module_load_success_message);
    #endif


    #ifdef documentation_module
    char* documents[] = {"Linked lists", "Queues", "Maps", "Binary Trees"};
    int* availability_mask = check_available_documentation_module(validate, DOCS_COUNT, 
                                        "Linked lists", "Queues", "Maps", "Binary Trees");
    

    if (availability_mask != NULL) {
        for (int i = 0; i < DOCS_COUNT; i++) {
            printf("[%-15s : %s]\n", documents[i], availability_mask[i] ? "available" : "unavailable");
        }
        free(availability_mask);
    }

    #endif
    
    return 0;
}

