#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

#include "matrix_func.h"
#include "input_matrix.h"
#include "matrix_struct.h"
#include "output_matrix.h"

static void make_matrix_for_calculation(MATRIX* m);

static void make_matrix_for_calculation(MATRIX* m) {
    input_matrix_size(&m->cols, &m->rows);
    matrix_init(m);
}

int sum_matrix() {

    MATRIX m1 = {}, m2 = {};

    make_matrix_for_calculation(&m1);
    make_matrix_for_calculation(&m2);

    if (m1.cols != m2.cols ||
        m1.rows != m2.rows) {
            printf("ERROR: INCORRET MATRIX INPUT\n");
            return -1;
        }

    int cols = m1.cols;
    int rows = m1.rows;


    for     (int col = 0;  col < cols; col++) {
        for (int row = 0; row < rows; row++) {

            *(m1.matrix + row * m1.cols + col) +=
            *(m2.matrix + row * m2.cols + col);
        }
    }

    print_rect_matrix(&m1);
    free(m1.matrix);
    free(m2.matrix);
    return 0;
}

int mult_matrix() {
    MATRIX m1 = {}, m2 = {}, m_res = {};

    make_matrix_for_calculation(&m1);
    make_matrix_for_calculation(&m2);

    if (m1.cols != m2.rows) {

        printf("ERROR: INCORRET MATRIX INPUT\n");
        return -1;

    }

    m_res.cols = m2.cols;
    m_res.rows = m1.rows;

    m_res.matrix = (double*)calloc(m_res.cols * m_res.rows, sizeof(double));

    for (int row = 0; row < m_res.rows; row++) {
        for (int col = 0; col < m_res.cols; col++) {

            double tmp = 0;

            for (int offset = 0; offset < m1.cols; offset++) {
                tmp += *(m1.matrix + row    * m1.cols + offset) *
                       *(m2.matrix + offset * m2.cols + col);
            }

            *(m_res.matrix + col * m_res.rows + row) = tmp;

        }
    }

    print_rect_matrix(&m_res);

    free(m_res.matrix);
    free(m1.matrix);
    free(m2.matrix);

    return 0;
}

int show_user_matrix() {
    MATRIX m = {};
    make_matrix_for_calculation(&m);
    print_rect_matrix(&m);
    return 0;
}
