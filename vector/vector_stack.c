#include <stdio.h>
#include <stdlib.h>
#include "../errors.h"
#include "../stack.h"

typedef struct Stack {
  char **vector;
  size_t len;
  int top;
} Stack;

Stack* create_stack(const size_t len) {
  Stack* stack = (Stack*)calloc(1, sizeof(Stack));
  stack->len = len;
  stack->vector = (char**)calloc(len, sizeof(char*));
  return stack;
}

int pull(Stack* stack, char** elem) {
  if (stack->top == 0) {
    return STACK_EMPTY;
  }
  (stack->top)--;
  *elem = stack->vector[stack->top];
  return NO_ERR;
}

int push(Stack* stack, char* elem) {
  if (stack->top == stack->len) {
    return STACK_FULL;
  }
  stack->vector[stack->top] = elem;
  (stack->top)++;
  return NO_ERR;
}

void clear_stack(Stack* stack) {
  char* str = NULL;
  int helper = pull(stack, &str);
  while (helper != STACK_EMPTY) {
    free(str);
    helper = pull(stack, &str);
  }
  free(stack->vector);
  free(stack);
}
