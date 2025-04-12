#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "process.h"
#include "errors.h"
#include "stack.h"

#define StackIsEmpty(helper, str1, str2) {if (helper == STACK_EMPTY) {free(str1); free(str2); return STACK_EMPTY;}}

int post_into_inf(Stack* stack, char** res_str) {
  if (stack == NULL) {
    return INVALID_PTR;
  }
  int helper = 0, operand_counter = 0, operation_counter = 0, total_operand_counter = 0;
  char operand = (char)getchar();
  while (operand != EOF && operand != '\0' && operand != '\n' && operand_counter <= 3) {
    if ((operand < 'A') || (operand > 'z') || (operand > 'Z' && operand < 'a')) {
      if (operand == '+' || operand == '-' || operand == '*' || operand == '/') {
        operand_counter = 0;
        operation_counter++;
        helper = get_expression(stack, operand);
        StackIsEmpty(helper, NULL, NULL);
        goto operation;
      } else {
        return INVALID_SYNTAX;
      }
    }
    total_operand_counter++;
    char* operand_str = (char*)calloc(2, sizeof(char));
    operand_str[0] = operand;
    helper = push(stack, operand_str);
    if (helper == STACK_FULL) {
      free(operand_str);
      return STACK_FULL;
    }
    operand_counter++;
    operation:
    operand = (char)getchar();
  }
  if (operand_counter > 3 || (total_operand_counter - 1 != operation_counter)) {
    return INVALID_SYNTAX;
  }
  helper = pull(stack, res_str);
  StackIsEmpty(helper, NULL, NULL);
  return NO_ERR;
}

int get_expression(Stack* stack, char operation) {
  int helper = 0;
  char* operation_str = (char*)calloc(2, sizeof(char));
  operation_str[0] = operation;
  char *operand_1 = NULL, *operand_2 = NULL;
  helper = pull(stack, &operand_2);
  StackIsEmpty(helper, operation_str, NULL);
  helper = pull(stack, &operand_1);
  StackIsEmpty(helper, operation_str, operand_2);
  char* out_str = get_str_for_push(operand_1, operand_2, operation_str);
  push(stack, out_str);
  return NO_ERR;
}

char* get_str_for_push(char* operand_1, char* operand_2, char* operation) {
  char* out_str = (char*)calloc(strlen(operand_2) + strlen(operand_1) + 4, sizeof(char));
  out_str[0] = '(';
  strcat(out_str, operand_1);
  strcat(out_str, operation);
  strcat(out_str, operand_2);
  out_str[strlen(out_str)] = ')';
  free(operand_2);
  free(operand_1);
  free(operation);
  return out_str;
}
