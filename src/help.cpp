#include <stdio.h>

#include "help.h"

int help() {
    printf("# Input only ONE argument:\n"
           "-s - matrix addition\n"
           "-m - matrix multiplication\n"
           "-p - input and print your matrix\n"
           "-h - show help\n");
    return 0;
}
