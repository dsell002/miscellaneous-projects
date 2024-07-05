#include <stdio.h>
#include <stdlib.h>

int main() {
    int *array;
    int size = 10;

    // Allocate memory
    array = (int *)malloc(size * sizeof(int));
    if (array == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Initialize and print the array
    for (int i = 0; i < size; i++) {
        array[i] = i * 2;
        printf("array[%d] = %d\n", i, array[i]);
    }

    // Deallocate memory
    free(array);
    return 0;
}
