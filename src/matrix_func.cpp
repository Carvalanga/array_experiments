#include <assert.h>
#include <stdlib.h>
#include <stdio.h>


#include "matrix_func.h"

void print_rect_mathix(int* arr, size_t x_size, size_t y_size) {
    for (int x = 0; x < x_size; x++) {
        for (int y = 0; y < y_size; y++) {

            assert(x < x_size);
            assert(y < y_size);

            printf("%-3d ", *(arr + x * y_size + y ));

            /*неверный ввод *(arr + x_size * y_size + y_size))*/

        }
        printf("\n");
    }
}

void print_triangle_matrix(int* arr, size_t num_count) {

    for (int i = 0; i < num_count; i++) {

        for (int j = 0; j <= i; j++) {

            printf("%-3d ", *(arr + j + arith_prog(1, i, i)));
            num_count--;

        }

        printf("\n");
    }
}

int arith_prog(int first_memb, int last_memb, int count_memb) {
    return (first_memb + last_memb) * count_memb / 2;
}
