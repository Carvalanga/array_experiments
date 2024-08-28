#include <stdlib.h>
#include <stdio.h>

#include "matrix_func.h"
#include "input_matrix.h"
#include "command_line.h"
#include "help.h"

int main(int argc, char* argv[]) {

    MODES mode = HELP;

    if (argc != 2){
        printf("# Too few or too much arguments, check the help:\n\n");
    }

    else {
        mode = arg_check(argv[1]);
    }

    return start_program(mode);
}
