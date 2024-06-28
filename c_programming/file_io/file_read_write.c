#include <stdio.h>

int main() {
    FILE *file;
    char buffer[100];

    // Write to a file
    file = fopen("example.txt", "w");
    if (!file) {
        perror("Failed to open file");
        return 1;
    }
    fprintf(file, "Hello, World!\n");
    fclose(file);

    // Read from a file
    file = fopen("example.txt", "r");
    if (!file) {
        perror("Failed to open file");
        return 1;
    }
    while (fgets(buffer, sizeof(buffer), file)) {
        printf("%s", buffer);
    }
    fclose(file);

    return 0;
}
