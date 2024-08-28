#ifndef MATRIX_FUNC_H
#define MATRIX_FUNC_H

#include "matrix_struct.h"

int sum_matrix();
void print_rect_matrix(MATRIX* mtrx);
void print_triangle_matrix(double* arr, size_t len, int max_num_len);
int check_max_num_len(double* ptr_cp, int num_cnt);

#endif //MATRIX_FUNC_H
