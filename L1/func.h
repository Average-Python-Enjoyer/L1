#ifndef INC_5_1_FUNCTIONS_H
#define INC_5_1_FUNCTIONS_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct GraphicsCard {
    char model[50];
    float gpu_clock;
    int year;
};

int create_array(struct GraphicsCard array[], int* size);
void print_array(struct GraphicsCard array[], int size);
int compare(const void* a, const void* b);
void sort_array(struct GraphicsCard array[], int size, int field);

#endif //INC_5_1_FUNCTIONS_H
