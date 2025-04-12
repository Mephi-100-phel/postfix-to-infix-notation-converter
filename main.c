#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "process.h"
#include "errors.h"
#include "stack.h"

static int process_argv(int, char**);
static int my_pow(int, int);

int main(int argc, char** argv) {
  int stack_len = process_argv(argc, argv);
  printf("%d\n", stack_len);
  Stack* stack = create_stack(stack_len);
  char* res_str = NULL;
  printf("Введите строку в постфиксной форме\n");
  int helper = post_into_inf(stack, &res_str);
  if (helper == INVALID_SYNTAX || helper == STACK_EMPTY) {
    printf("INVALID_SYNTAX\n");
    goto end;
  }
  if (helper == STACK_FULL) {
    printf("STACK_FULL\n");
    goto end;
  }
  printf("Строка в инфиксной форме: %s\n", res_str);

  end:
  free(res_str);
  clear_stack(stack);
  return helper;
}

static int process_argv(int argc, char** argv) {
  if (argc == 1) {
    return 5;
  }
  char* str = argv[1];
  int len = strlen(str), res_len = 0;
  for (int i = 0; i < len; i++) {
    int elem = (int)str[i] - (int)'0';
    if (elem < 0 || elem > 9) {
      return 5;
    }
    res_len += elem * my_pow(10, len - i - 1);
  }
  return res_len;
}

static int my_pow(int x, int y) {
  if (y == 0) {
    return 1;
  }
  int res = 1;
  for (int i = 0; i < y; i++) {
    res *= x;
  }
  return res;
}
