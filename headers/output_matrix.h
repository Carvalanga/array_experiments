#ifndef OUTPUT_MATRIX_H
#define OUTPUT_MATRIX_H

#include <math.h>

#include "matrix_struct.h"

int check_max_num_len(double* ptr_cp, int num_cnt);
void print_rect_matrix(MATRIX* mtrx);
void print_triangle_matrix(double* arr, size_t len, int max_num_len);

#endif //OUTPUT_MATRIX_H
