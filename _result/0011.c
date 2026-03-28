#include <stdbool.h>
#include <stdio.h>

static int max(int a, int b) { return (a > b ? a : b); }

static int min(int a, int b) { return (a < b ? a : b); }

int maxArea(int *height, int heightSize) {
  int maxArea = 0;

  int left = 0, right = heightSize - 1;
  while (left < right) {
    maxArea = max(maxArea, (right - left) * min(height[left], height[right]));
    height[left] < height[right] ? left++ : right--;
  }

  return (maxArea);
}

int main(int ac, char **av) {
  (void)ac;

  int height[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
  int heightSize = 9;

  printf("%d\n", maxArea(height, heightSize));
  return 0;
}
