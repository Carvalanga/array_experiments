#include <stdlib.h>
#include <stdio.h>

#include "input_matrix.h"

void input_matrix_size(int* x, int* y) {
    printf("# Input count of cols:\n");
    scanf("%i", x);

    printf("# Input count of rows:\n");
    scanf("%i", y);
}

void matrix_init(MATRIX* m) {

    int val_count = m->size_x * m->size_y;
    m->matrix = (double*)calloc(val_count, sizeof(double));

    double* ptr = m->matrix;

    printf("# Input data for matrix:");
    for (; val_count > 0; val_count--) {

        scanf("%lg", ptr++);
    }
}
