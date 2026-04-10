#include <stdio.h>
#include <stdlib.h>

// qソートする
// 2番目までの合計をbest変数で持っておく
// numsSize - 2までfor回して、その中でsumとtargetの大小関係でleftとrightのポイントをずらしていく。
// bestの更新方法は、abs(sum-target) < abs(best-target) が成り立つ時best = sumになる

static int cmp(const void* a, const void* b) {
  int x = *(int*)a, y = *(int*)b;
  return (x > y) - (x < y);
}

int threeSumClosest(int* nums, int numsSize, int target) {
  qsort(nums, numsSize, sizeof(*nums), cmp);

  int best = nums[0] + nums[1] + nums[2];
  for (int i = 0; i < numsSize - 2; i++) {
    int left = i + 1, right = numsSize - 1;
    while (left < right) {
      int sum = nums[i] + nums[left] + nums[right];

      if (abs(sum - target) < abs(best - target)) {
        best = sum;
      }

      if (sum < target) {
        left++;
      } else if (sum > target) {
        right--;
      } else {
        return (sum);
      }
    }
  }

  return best;
}

int main(void) {
  printf("Hello world!");
  return 0;
}
