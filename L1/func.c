#define _CRT_SECURE_NO_WARNINGS
#define MAX_SIZE 100
#include "func.h"



int create_array(struct GraphicsCard array[], int* size) {
    if (*size != 0) {
        printf("\033[0;33m Array already created\n\033[0m");
        return -1;
    }
    int n;
    printf("\033[0;37m Enter number of graphics cards to add: \033[0m");
    while (scanf("%d", &n) != 1 || n <= 0 || getchar() != '\n') {
        printf("\033[0;33m RETRY:\033[0m");
        rewind(stdin);
    }

    if (n <= 0 || n > MAX_SIZE) {
        printf("\033[0;33m Invalid size\n\033[0m");
        return -1;
    }
    for (int i = 0; i < n; i++) {
        struct GraphicsCard card;
        printf("\033[0;37m Enter model of graphics card %d: \033[0m", i + 1);
        fgets(card.model, 50, stdin);
        card.model[strcspn(card.model, "\n")] = '\0';


        printf("\033[0;37m Enter GPU clock of graphics card %d: \033[0m", i + 1);
        while (scanf_s("%f", &card.gpu_clock) != 1 || card.gpu_clock <= 0) {
            printf("\033[0;33m RETRY:\033[0m");
            rewind(stdin);
        }

        while (getchar() != '\n');

        printf("\033[0;37m Enter year of graphics card %d: \033[0m", i + 1);
        while (scanf_s("%d", &card.year) != 1 || card.year <= 0) {
            printf("\033[0;33m RETRY:\033[0m");
            rewind(stdin);
        }

        array[i] = card;
        while (getchar() != '\n');
    }
    *size = n;
    printf("\033[0;32m Array created\n\033[0m");
    return 0;
}

void print_array(struct GraphicsCard array[], int size) {
    if (size == 0) {
        printf("\033[0;33m Array is empty\n\033[0m");
    }
    else {
        printf("\033[0;37m Graphics cards:\n \033[0m");
        for (int i = 0; i < size; i++) {
            printf("\033[0;37m %d. Model: %s, GPU clock: %.2f GHz, Year: %d\n \033[0m", i + 1, array[i].model, array[i].gpu_clock, array[i].year);
        }
    }
}


int compare(const void* a, const void* b) {
    const struct GraphicsCard* card1 = (const struct GraphicsCard*)a;
    const struct GraphicsCard* card2 = (const struct GraphicsCard*)b;
    return card1->year - card2->year;
}
void swap(struct GraphicsCard* a, struct GraphicsCard* b) {
    struct GraphicsCard temp = *a;
    *a = *b;
    *b = temp;
}

void sort_by_gpu_clock(struct GraphicsCard array[], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (array[i].gpu_clock < array[j].gpu_clock) {
                swap(&array[i], &array[j]);
            }
        }
    }
}

void sort_array(struct GraphicsCard array[], int size, int field) {
    switch (field) {
    case 1:
        qsort(array, size, sizeof(struct GraphicsCard), compare);
        break;
    case 2:
        sort_by_gpu_clock(array, size);
        break;
    default:
        printf("\033[0;33m Invalid field\n\033[0m");
        break;
    }
}
