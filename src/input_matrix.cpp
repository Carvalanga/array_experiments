#include <stdlib.h>
#include <stdio.h>

#include "input_matrix.h"

void input_matrix_size(int* cols, int* rows) {
    printf("# Input count of cols:\n");
    scanf("%i", cols);

    printf("# Input count of rows:\n");
    scanf("%i", rows);
}

void matrix_init(MATRIX* m) {

    int val_count = m->cols * m->rows;
    m->matrix = (double*)calloc(val_count, sizeof(double));

    double* ptr = m->matrix;

    printf("# Input data for matrix:\n");
    for (; val_count > 0; val_count--) {

        scanf("%lg", ptr++);
    }
}
