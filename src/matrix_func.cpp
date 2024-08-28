#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "matrix_func.h"
#include "input_matrix.h"
#include "matrix_struct.h"

void print_rect_matrix(MATRIX* mtrx) {

    int max_num_len = check_max_num_len(mtrx->matrix, mtrx->size_x * mtrx->size_y);

    printf("\n"
           "# Your matrix:"
           "\n");

    for (int y = 0; y < mtrx->size_y; y++) {

        printf("\t");

        for (int x = 0; x < mtrx->size_x; x++) {

            assert(x < mtrx->size_x && x >= 0);
            assert(y < mtrx->size_y && y >= 0);

            printf("%-*lg ", max_num_len, *(mtrx->matrix + x * mtrx->size_y + y ));

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

int sum_matrix() {

    int x_size = 1, y_size = 1;

    input_matrix_size(&x_size,
                      &y_size);

    MATRIX m1 = {}, m2 = {};

    m1.size_x = x_size;
    m1.size_y = y_size;

    m2.size_x = x_size;
    m2.size_y = y_size;

    matrix_init(&m1);
    matrix_init(&m2);

    for     (int x = 0; x < x_size; x++) {
        for (int y = 0; y < y_size; y++) {

            *(m1.matrix + x * m1.size_y + y) +=
            *(m2.matrix + x * m2.size_y + y);

            printf("%lg\n",*(m1.matrix + x * y_size + y));
        }
    }

    print_rect_matrix(&m1);
    free(m1.matrix);
    free(m2.matrix);
    return 0;
}

//int mult_matrix () {
//    MATRIX m1 = {}, m2 = {};
//
//    input_matrix_size(&m1.size_x,
//                      &m1.size_y);
//
//    input_matrix_size(&m2.size_x,
//                      &m2.size_y);
//
//    if (!check_correct_matrix_input(
//    m1.size_x,
//    m1.size_y,
//    m2.size_x,
//    m2.size_y) {
//
//        printf("ERROR: INCORRET MATRIX INPUT\n");
//
//    }
//
//    for
//}

