#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/**
> The overall run time complexity should be O(log (m+n))
を目指す。

nums1とnums2の両方を足し合わせた配列を作るのは、計算量が上のを超えてしまいそう
nums1[i]とnums2[i]を比べて小さい方と大きい方の順番に数えていく

ex) [1,3], [2, 4] => i = 0のとき、[1,2] i = 1のとき、[3,4]になって、
新しく配列を作らずともソート済みだから数えていくだけで良さそう

で、事前にnums1Size+nums2Sizeの結果/2 が中央の添字だから、
数えている時に、その添字番目になったらそれを出力。

で、偶数と奇数を考慮しないといけないから、偶数なら
target(真ん中のindex)は2ついる。 奇数なら1つでいい。

even: (nums1Size+nums2Size)/2, (nums1Size+nums2Size-1)/2
odd: nums1Size+nums2Size/2 かな？
もう少し綺麗にここ出来そう

配列外参照について
- nums1: [], nums2: [1,2] => i1 >= nums1Size
- nums1: [1,2], nums2: [] => i2 >= nums2Size
*/

double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2,
                              int nums2Size) {
  size_t total = nums1Size + nums2Size;
  size_t left = (total - 1) / 2;
  size_t right = total / 2;

  size_t i1 = 0, i2 = 0;
  int cur = 0;
  int left_val = 0, right_val = 0;

  for (size_t k = 0; k <= right; k++) {
    // 次に取る値を決める セグフォ対策
    if (i2 >= (size_t)nums2Size ||
        i1 < (size_t)nums1Size && nums1[i1] < nums2[i2]) {
      // num1のみ
      cur = nums1[i1++];
    } else {
      // num2のみ
      cur = nums2[i2++];
    }

    if (k == left)
      left_val = cur;
    if (k == right)
      right_val = cur;
  }

  double ans = (left_val + right_val) / 2.0;
  return (ans);
}

static int parse_ints(char **av, int base, size_t len, int *out) {
  for (size_t i = 0; i < len; i++) {
    out[i] = atoi(av[base + i]);
  }

  return (0);
}

int main(int ac, char **av) {
  if (ac < 3)
    return (1);

  size_t m = atoi(av[1]);
  size_t n = atoi(av[2]);
  if (ac < 3 + m + n)
    return (1);

  int *nums1 = calloc(m, sizeof(*nums1));
  int *nums2 = calloc(n, sizeof(*nums2));
  if (!nums1 || !nums2)
    return (1);

  parse_ints(av, 3, m, nums1);
  parse_ints(av, 3 + m, n, nums2);

  printf("%lf", findMedianSortedArrays(nums1, m, nums2, n));

  free(nums1);
  free(nums2);
  return (0);
}
