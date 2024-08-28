#include <stdio.h>
#include <assert.h>

#include "output_matrix.h"

void print_rect_matrix(MATRIX* mtrx) {

    int max_num_len = check_max_num_len(mtrx->matrix, mtrx->cols * mtrx->rows);

    printf("\n"
           "# Your matrix:"
           "\n");
    for (int col = 0; col < mtrx->cols; col++) {

        printf("\t");

        for (int row = 0; row < mtrx->rows; row++) {

            assert(col < mtrx->cols && col >= 0);
            assert(row < mtrx->rows && row >= 0);

            printf("%-*lg ", max_num_len, *(mtrx->matrix + col * mtrx->rows + row));

        }

        printf("\n");
    }
}

void print_triangle_matrix(double* arr, size_t num_count, int max_num_len) {

    printf("\n"
           "# Your triangle matrix:"
           "\n");

    for (size_t i = 0; i < num_count; i++) {
        printf("\t");

        for (size_t j = 0; j <= i; j++) {
            printf("%-*lg ", max_num_len, *(arr++));
            num_count--;
        }

        printf("\n");
    }

    printf("\t");

    for (; num_count > 0; num_count--) {
        printf("%-*lg ", max_num_len, *(arr++));
    }
}

int check_max_num_len(double* ptr_cp, int num_cnt) {

    int mx_len = 1;

    for (int i = 0; i < num_cnt; i++) {
        if (log10(*ptr_cp) > mx_len) {
            mx_len = (int)floor(log10(*ptr_cp));
        }
        ptr_cp++;
    }

    return mx_len+2;
}
