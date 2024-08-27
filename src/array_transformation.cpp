#include <stdlib.h>
#include <stdio.h>

#include "matrix_func.h"
#include "input_matrix.h"

int main() {

    int matrix_size_x = 1;
    int matrix_size_y = 1;

    double* ptr = input_matrix(&matrix_size_x, &matrix_size_y);

    print_rect_mathix(ptr, matrix_size_x,
                           matrix_size_y);

    print_triangle_matrix(ptr, matrix_size_x * matrix_size_y);

    free(ptr);

}
