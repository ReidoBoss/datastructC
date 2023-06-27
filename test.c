#include <stdio.h>

int main() {
    int value = 42;
    int* pointer = &value;

    printf("Original value: %d\n", value);

    *pointer = 100;

    printf("Modified value: %d\n", value);

    return 0;
}
