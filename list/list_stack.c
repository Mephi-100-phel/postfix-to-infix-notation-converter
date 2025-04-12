#include <stdio.h>
#include <stdlib.h>
#include "../errors.h"
#include "../stack.h"

typedef struct Node {
  char* data;
  struct Node* next;
} Node;

typedef struct Stack {
  Node* top;
} Stack;

Stack* create_stack(const size_t len) {
  Stack* stack = (Stack*)calloc(1, sizeof(Stack));
  stack->top = (Node*)calloc(1, sizeof(Node));
  return stack;
}

int pull(Stack* stack, char** elem) {
  if (stack == NULL) {
    return INVALID_PTR;
  }
  if (stack->top == NULL || stack->top->data == NULL) {
    return STACK_EMPTY;
  }
  Node* temp = stack->top;
  stack->top = temp->next;
  *elem = temp->data;
  free(temp);
  return NO_ERR;
}

int push(Stack* stack, char* elem) {
  if (stack == NULL || elem == NULL) {
    return INVALID_PTR;
  }
  Node *new_node = (Node*)calloc(1, sizeof(Node)), *temp = stack->top;
  stack->top = new_node;
  new_node->next = temp;
  new_node->data = elem;
  return NO_ERR;
}

void clear_stack(Stack* stack) {
  char* str = NULL;
  int helper = pull(stack, &str);
  while (helper != STACK_EMPTY) {
    free(str);
    helper = pull(stack, &str);
  }
  free(stack->top);
  free(stack);
}
