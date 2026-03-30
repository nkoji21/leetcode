#include <stdio.h>

static inline int max(int a, int b) { return a < b ? b : a; }
static inline int min(int a, int b) { return a < b ? a : b; }

int main(void) {
  printf("Hello world!");
  return 0;
}
