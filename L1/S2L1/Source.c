#define _CRT_SECURE_NO_WARNINGS
#define MAX_SIZE 100
#include "func.h"

struct GraphicsCard {
    char model[50];
    float gpu_clock;
    int year;
};

int main() {
    struct GraphicsCard array[MAX_SIZE];
    int size = 0;
    int operation = 0;
    while (operation != 7) {
        printf("\nSelect operation:\n");
        printf("1. Create array of graphics cards\n");
        printf("2. Print array of graphics cards\n");
        printf("3. Do nothing\n");
        printf("4. Sort array by year\n");
        printf("5. Sort array by GPU clock\n");
        printf("6. Clear array\n");
        printf("7. Exit\n");
        printf("Enter operation number: ");
        scanf("%d", &operation);
        printf("\n");
        switch (operation) {
        case 1:
            create_array(array, &size);
            while (getchar() != '\n');
            break;
        case 2:
            print_array(array, size);
            while (getchar() != '\n');
            break;
        case 3:
            printf("\033[0;32m NOTHING HAPPANED! YAY!\n \033[0m");
            while (getchar() != '\n');
            break;
        case 4:
            sort_array(array, size, 1);
            printf("\033[0;32m Array sorted by year\n \033[0m");
            while (getchar() != '\n');
            break;
        case 5:
            sort_array(array, size, 2);
            printf("\033[0;32m Array sorted by GPU clock\n \033[0m");
            while (getchar() != '\n');
            break;
        case 6:
            size = 0;
            printf("\033[0;32m Array cleared\n \033[0m");
            while (getchar() != '\n');
            break;
        case 7:
            printf("\033[0;32m Exiting program\n \033[0m");
            while (getchar() != '\n');
            break;
        default:
            printf("\033[0;33m Invalid operation\n \033[0m");
            while (getchar() != '\n');
            fflush(stdin);
            break;
        }
    }
    return 0;
}


