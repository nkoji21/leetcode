#include <stdio.h>

static inline int max(int a, int b) { return a < b ? b : a; }
static inline int min(int a, int b) { return a < b ? a : b; }

// comparison function signature for qsort()
static int cmp(const void* a, const void* b) {
  int x = *(int*)a, y = *(int*)b;
  return (x > y) - (x < y);
}

int main(void) {
  printf("Hello world!");
  return 0;
}
