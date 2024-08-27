#include <stdlib.h>
#include <stdio.h>

#include "input_matrix.h"

double* input_matrix(int* x, int* y) {

    scanf("%i %i", x, y);

    int val_count = (*x) * (*y);

    double* matrix_ptr = (double*)calloc(val_count, sizeof(double));
    double* ptr = matrix_ptr;

    for (; val_count > 0; val_count--) {
        scanf("%lg", ptr++);
    }

    return(matrix_ptr);

}
