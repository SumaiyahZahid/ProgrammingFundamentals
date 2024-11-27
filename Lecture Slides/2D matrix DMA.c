#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows = 3, cols = 4; // Dimensions of the matrix
    int **matrix;
    int i,j;

    // Step 1: Allocate memory for row pointers
    matrix = (int **)malloc(rows * sizeof(int *));
    if (matrix == NULL) {
        printf("Memory allocation failed for rows.\n");
        return 1;
    }

    // Step 2: Allocate memory for each row
    for (i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
        if (matrix[i] == NULL) {
            printf("Memory allocation failed for row %d.\n", i);
            return 1;
        }
    }

    // Step 3: Initialize the matrix
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            matrix[i][j] = i * cols + j; // Example initialization
        }
    }

    // Step 4: Print the matrix
    printf("Matrix:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Step 5: Free allocated memory
    for (i = 0; i < rows; i++) {
        free(matrix[i]); // Free each row
    }
    free(matrix); // Free the row pointers

    return 0;
}

