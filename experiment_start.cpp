#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

void print_arr(int* arr, size_t x_size, size_t y_size);
void print_not_rect_arr(int** arr, size_t num_count);
void print_triangle_matrix(int* arr, size_t len);
int arith_prog(int first_memb, int last_memb, int count_memb);
size_t get_arr_size(int* arr);

int main() {
    int two_dimensional_array[][6] = {
        { 1,  2,  3,  4,  5,  6},
        { 7,  8,  9, 10, 11, 12},
        {13, 14, 15, 16, 17, 18}
    };

    int test_triangle[] = {1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6, 7, 7, 8, 8};
    int a[] = {12, 23};
    int b[] = {1, 2, 3, 4, 5};
    int c[] = {1};

    int* ptr_arr[3] = {a, b, c};

    //print_arr(*two_dimensional_array, sizeof(two_dimensional_array) / sizeof(*two_dimensional_array), sizeof(*two_dimensional_array) / sizeof(**two_dimensional_array));
    //print_not_rect_arr(ptr_arr, sizeof(ptr_arr) / sizeof(*ptr_arr));
    print_triangle_matrix(test_triangle, sizeof(test_triangle) / sizeof(*test_triangle));
}

void print_arr(int* arr, size_t x_size, size_t y_size) {
    for (int x = 0; x < x_size; x++) {
        for (int y = 0; y < y_size; y++) {

            assert(x < x_size);
            assert(y < y_size);

            printf("%3d ", *(arr + x * y_size + y ));

            /*неверный ввод *(arr + x_size * y_size + y_size))*/

        }
        printf("\n");
    }
}

void print_triangle_matrix(int* arr, size_t num_count) {

    for (int i = 0; i < num_count; i++) {

        for (int j = 0; j <= i; j++) {

            printf("%d ", *(arr + j + arith_prog(1, i, i)));
            num_count--;

        }

        printf("\n");
    }
}

void print_not_rect_arr(int* arr[], size_t len_arr) {

    printf("%d\n", len_arr);
    for (size_t i = 0; i < len_arr; i++) {

        size_t nested_arr_len = sizeof(*(arr+i)) / sizeof(**(arr+i));

        for (size_t j = 0; j < nested_arr_len; j++) {

            printf("arr[%i][%j] = %d\n", i, j, *(*(arr+i) + j));
        }
    }
}

int arith_prog(int first_memb, int last_memb, int count_memb) {
    return (first_memb + last_memb) * count_memb / 2;
}
