#ifndef COMMAND_LINE_H
#define COMMAND_LINE_H

enum MODES {
    SUM,
    MULT,
    SHOW,
    HELP,
    TORN
};

MODES arg_check(char* arg);
int start_program(MODES md);

#endif //COMMAND_LINE_H
