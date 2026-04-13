#include <stdio.h>

int removeDuplicates(int* nums, int numsSize) {
  if (nums == NULL) {
    return 0;
  }

  int k = 1;
  for (int i = 1; i < numsSize; i++) {
    if (nums[i] != nums[k - 1]) {
      nums[k] = nums[i];
      k++;
    }
  }

  return k;
}

int main(void) {
  int nums[] = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
  printf("%d\n", removeDuplicates(nums, 10));
  return 0;
}
