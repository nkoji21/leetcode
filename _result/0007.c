#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool isOverflow(long x) { return (x < INT_MIN || x > INT_MAX); }

static long rev_calc(long x, long *acc) {
  if (x == 0)
    return (0);

  *acc = *acc * 10 + (x % 10);
  return (rev_calc(x / 10, acc));
}

int reverse(int x) {
  long abs_x = x;
  if (x < 0)
    abs_x = -abs_x;

  long acc = 0;
  rev_calc(abs_x, &acc);

  long reversed = (x < 0) ? -acc : acc;
  return (isOverflow(reversed) ? 0 : (int)reversed);
}

int main(int ac, char **av) {
  (void)ac;

  printf("%d\n", reverse(atoi(av[1])));
  return (0);
}
