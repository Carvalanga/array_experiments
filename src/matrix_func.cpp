#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "matrix_func.h"

void print_rect_mathix(double* arr, size_t x_size, size_t y_size) {

    printf("\n"
           "#  Your rectangle matrix:"
           "\n");

    for (size_t y = 0; y < y_size; y++) {
        printf("\t");
        for (size_t x = 0; x < x_size; x++) {

            assert(x < x_size);
            assert(y < y_size);

            printf("%-3lg ", *(arr + x * y_size + y ));

            /*неверный ввод *(arr + x_size * y_size + y_size))*/

        }
        printf("\n");
    }
}

void print_triangle_matrix(double* arr, size_t num_count) {

    printf("\n"
           "# Your triangle matrix:"
           "\n");

    for (size_t i = 0; i < num_count; i++) {

        printf("\t");

        for (size_t j = 0; j <= i; j++) {

            printf("%-3lg ", *(arr + j + arith_prog(1, i, i)));
            num_count--;

        }

        printf("\n");
    }
}

int arith_prog(int first_memb, int last_memb, int count_memb) {
    return (first_memb + last_memb) * count_memb / 2;
}
