#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int numStrings = 3; // Number of strings
    int maxLength = 50; // Maximum length of each string
    char **strings;
    int i;

    // Step 1: Allocate memory for the array of string pointers
    strings = (char **)malloc(numStrings * sizeof(char *));
    if (strings == NULL) {
        printf("Memory allocation failed for strings.\n");
        return 1;
    }

    // Step 2: Allocate memory for each string
    for (i = 0; i < numStrings; i++) {
        strings[i] = (char *)malloc(maxLength * sizeof(char));
        if (strings[i] == NULL) {
            printf("Memory allocation failed for string %d.\n", i);
            return 1;
        }
    }

    // Step 3: Assign values to the strings
    strcpy(strings[0], "Hello, world!");
    strcpy(strings[1], "Dynamic allocation");
    strcpy(strings[2], "Array of strings");

    // Step 4: Print the strings
    printf("Strings:\n");
    for (i = 0; i < numStrings; i++) {
        printf("%s\n", strings[i]);
    }

    // Step 5: Free the allocated memory
    for (i = 0; i < numStrings; i++) {
        free(strings[i]); // Free each string
    }
    free(strings); // Free the array of pointers

    return 0;
}

