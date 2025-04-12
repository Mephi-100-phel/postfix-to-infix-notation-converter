#ifndef PROCESS_H
#define PROCESS_H

#include "stack.h"

int post_into_inf(Stack*, char**);
int get_expression(Stack*, char);
char* get_str_for_push(char*, char*, char*);

#endif
