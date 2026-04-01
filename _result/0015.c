#include <stdio.h>
#include <stdlib.h>

/**
[-1, 0, 1, 2, -1, -4]
-4, -1, -1, 0, 1, 2

-4 + 2 = -2 nai
-1 + 2 = 1 nai
-1 + 1 = 0 aru
-1 + 0 = -1 aru
*/

static int cmp(const void* a, const void* b) {
  int x = *(int*)a, y = *(int*)b;
  return (x > y) - (x < y);
}

static void free_results(int** result, int** columnSizes, size_t count) {
  for (size_t i = 0; i < count; i++) {
    free(result[i]);
  }
  free(result);
  free(*columnSizes);
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
  int maxResults = numsSize * numsSize / 6;  // C(n,k) = n(n-1)(n-2)..(n-k+1) / k!

  *returnColumnSizes = malloc(maxResults * sizeof(*returnColumnSizes));
  if (*returnColumnSizes == NULL) return (NULL);

  int** result = malloc(maxResults * sizeof(*result));
  if (result == NULL) return (free(*returnColumnSizes), NULL);

  qsort(nums, numsSize, sizeof(*nums), cmp);

  *returnSize = 0;
  for (int i = 0; i < numsSize - 2; i++) {
    if (i > 0 && nums[i] == nums[i - 1]) continue;  // duplicate
    if (nums[i] > 0) break;                         // ソートした結果最初が0を超えてるのなら解は無い

    int L = i + 1;
    int R = numsSize - 1;
    int target = -nums[i];

    while (L < R) {
      int sum = nums[L] + nums[R];
      if (sum == target) {
        result[*returnSize] = malloc(3 * sizeof(**result));
        if (result[*returnSize] == NULL) {
          free_results(result, returnColumnSizes, *returnSize);
          *returnSize = 0;
          return (NULL);
        }
        result[*returnSize][0] = nums[i];
        result[*returnSize][1] = nums[L];
        result[*returnSize][2] = nums[R];
        (*returnColumnSizes)[*returnSize] = 3;
        (*returnSize)++;

        // duplicate
        while (L < R && nums[L] == nums[L + 1]) L++;
        while (L < R && nums[R] == nums[R - 1]) R--;

        L++;
        R--;
      } else if (sum < target) {
        L++;
      } else if (sum > target) {
        R--;
      }
    }
  }
  return (result);
}

int main(int ac, char** av) {
  (void)ac;

  printf("%s\n", av[1]);
  return 0;
}
