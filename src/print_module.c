#include <stdio.h>
#include <time.h>

#include "print_module.h"

char print_char(char ch) 
{
    return putchar(ch);
}

void print_log(char (*print)(char), char* message) {
    time_t rawtime;
    struct tm * timeinfo;
    char buffer[9]; 
    
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    strftime(buffer, sizeof(buffer), "%H:%M:%S", timeinfo);
    
    const char *prefix = Log_prefix;
    while (*prefix) print(*prefix++);
    print(' ');
    for (int i = 0; buffer[i]; ++i) print(buffer[i]);
    print(' ');
    while (*message) print(*message++);
    print('\n');
}
