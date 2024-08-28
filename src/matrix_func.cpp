#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

#include "matrix_func.h"
#include "input_matrix.h"
#include "matrix_struct.h"
#include "output_matrix.h"

int sum_matrix() {

    int cols = 1, rows = 1;

    input_matrix_size(&cols,
                      &rows);

    MATRIX m1 = {}, m2 = {};

    m1.cols = m2.cols = cols;
    m1.rows = m2.rows = rows;

    matrix_init(&m1);
    matrix_init(&m2);

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

    input_matrix_size(&m1.cols,
                      &m1.rows);

    input_matrix_size(&m2.cols,
                      &m2.rows);

    if (m1.cols != m2.rows) {

        printf("ERROR: INCORRET MATRIX INPUT\n");
        return -1;

    }

    m_res.cols = m2.cols;
    m_res.rows = m1.rows;

    matrix_init(&m1);
    matrix_init(&m2);

    print_rect_matrix(&m1);

    m_res.matrix = (double*)calloc(m_res.cols * m_res.rows, sizeof(double));

    for (int row = 0; row < m_res.rows; row++) {
        for (int col = 0; col < m_res.cols; col++) {

            double tmp = 0;

            for (int epsilone = 0; epsilone < m1.cols; epsilone++) {
                tmp += *(m1.matrix + row * m1.cols + epsilone) *
                       *(m2.matrix + epsilone * m2.cols + col);
            }

            *(m_res.matrix + row * m_res.cols + col) = tmp;

        }
    }

    print_rect_matrix(&m_res);

    free(m_res.matrix);
    free(m1.matrix);
    free(m2.matrix);

    return 0;
}
