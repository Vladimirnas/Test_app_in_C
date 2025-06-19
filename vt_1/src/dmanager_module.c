// src/dmanager_module.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "door_struct.h"

#define DOORS_COUNT 15
#define MAX_ID_SEED 10000

void initialize_doors(struct door* doors);


void sort_doors_by_id(struct door* doors, int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (doors[j].id > doors[j + 1].id) {
                struct door temp = doors[j];
                doors[j] = doors[j + 1];
                doors[j + 1] = temp;
            }
        }
    }
}


void close_all_doors(struct door* doors, int count) {
    for (int i = 0; i < count; i++) {
        doors[i].status = 0;
    }
}


void print_doors(const struct door* doors, int count) {
    for (int i = 0; i < count; i++) {
        printf("%d, %d\n", doors[i].id, doors[i].status);
    }
}

int main() {
    struct door doors[DOORS_COUNT];

    initialize_doors(doors);
    sort_doors_by_id(doors, DOORS_COUNT);
    close_all_doors(doors, DOORS_COUNT);
    print_doors(doors, DOORS_COUNT);

    return 0;
}

// ATTENTION!!!
// DO NOT CHANGE!
void initialize_doors(struct door* doors) {
    srand(time(0));

    int seed = rand() % MAX_ID_SEED;
    for (int i = 0; i < DOORS_COUNT; i++) {
        doors[i].id = (i + seed) % DOORS_COUNT;
        doors[i].status = rand() % 2;
    }
}
