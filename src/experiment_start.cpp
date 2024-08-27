#include <stdlib.h>
#include <stdio.h>

#include "matrix_func.h"

int main() {
    int matrix_size_x = 1,
        matrix_size_y = 1;

    scanf("%i %i", &matrix_size_x,
                   &matrix_size_y);

    int val_count = matrix_size_x *
                    matrix_size_y;

    double* matrix_ptr = (double*)calloc(val_count, sizeof(double));
    double* ptr = matrix_ptr;

    for (; val_count > 0; val_count--) {
        scanf("%lg", ptr++);
    }

    ptr = matrix_ptr;

    for     (int x = 0; x < matrix_size_x; x++) {
        for (int y = 0; y < matrix_size_y; y++) {
            printf("%-3.2g ", *ptr++);
        }
        printf("\n");
    }

    free(matrix_ptr);

}
