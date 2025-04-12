#ifndef STACK_H
#define STACK_H

typedef struct Stack Stack;

Stack* create_stack(const size_t);
int pull(Stack*, char**);
int push(Stack*, char*);
void clear_stack(Stack*);

#endif
