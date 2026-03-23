#include <ctype.h>
#include <limits.h>
#include <stdio.h>

/**
空白スキップ -> 符号 -> 数字
*/
int myAtoi(char *s) {
  long ans = 0;
  int sign = 1;

  while (isspace((unsigned char)*s))
    s++;

  if (*s == '+' || *s == '-') {
    sign = (*s == '-') ? -1 : 1;
    s++;
  }

  while (isdigit((unsigned char)*s)) {
    ans = ans * 10 + (*s - '0');
    if (ans > INT_MAX)
      break;
    s++;
  }

  ans *= sign;

  if (ans > INT_MAX)
    return (INT_MAX);
  if (ans < INT_MIN)
    return (INT_MIN);
  return ((int)ans);
}

int main(int ac, char **av) {
  (void)ac;

  printf("%d\n", myAtoi(av[1]));
  return 0;
}
