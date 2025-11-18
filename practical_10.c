#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *inputFile, *outputFile;
    char inputName[50], outputName[50];
    char ch;

    // Get file names
    printf("Enter source file name: ");
    scanf("%s", inputName);

    printf("Enter destination file name: ");
    scanf("%s", outputName);

    // Open source file
    inputFile = fopen(inputName, "r");
    if (inputFile == NULL) {
        printf("Error: Cannot open source file.\n");
        exit(1);
    }

    // Create/Open destination file
    outputFile = fopen(outputName, "w");
    if (outputFile == NULL) {
        printf("Error: Cannot create destination file.\n");
        fclose(inputFile);
        exit(1);
    }

    // Copy contents character by character
    while ((ch = fgetc(inputFile)) != EOF) {
        fputc(ch, outputFile);
    }

    printf("File copied successfully.\n");

    // Close files
    fclose(inputFile);
    fclose(outputFile);

    return 0;
}
