#include <stdlib.h>
#include <stdio.h>

#include "matrix_func.h"
#include "input_matrix.h"

int main() {

    int matrix_size_x = 1;
    int matrix_size_y = 1;

    double* ptr = input_matrix(&matrix_size_x, &matrix_size_y);
    int num_cnt = matrix_size_x * matrix_size_y;
    int max_num_len = check_max_num_len(ptr, num_cnt);

    print_rect_mathix(ptr, matrix_size_x,
                           matrix_size_y,
                           max_num_len);

    print_triangle_matrix(ptr, num_cnt, max_num_len);

    free(ptr);

}
