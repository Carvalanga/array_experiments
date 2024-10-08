#include <string.h>
#include <stdio.h>

#include "command_line.h"
#include "matrix_func.h"
#include "help.h"

MODES arg_check(char* arg) {

    if (strcmp(arg, "-s") == 0) {
        return SUM;
    }

    else if (strcmp(arg, "-m") == 0) {
        return MULT;
    }

    else if (strcmp(arg, "-p") == 0) {
        return SHOW;
    }

    else if (strcmp(arg, "-h") == 0) {
        return HELP;
    }

    else if (strcmp(arg, "-t") == 0) {
        return TORN;
    }

    else
        printf("# Incorrect argument: check the help:\n\n");
        return HELP;

}

int start_program(MODES md) {

    switch(md) {

        case SUM:
            return sum_matrix();

        case MULT:
            return mult_matrix();

        case SHOW:
            return show_user_matrix();

        case HELP:
            return help();

        case TORN:
            return -1;
        default:
            printf("# ERROR: INCORRECT MODE");
            return -1;
    }


}
