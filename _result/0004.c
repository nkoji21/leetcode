#include <limits.h>

static int max(int a, int b) { return (a > b) ? a : b; }
static int min(int a, int b) { return (a < b) ? a : b; }

double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2,
                              int nums2Size) {
  if (nums1Size > nums2Size) {
    return (findMedianSortedArrays(nums2, nums2Size, nums1, nums1Size));
  }

  int m = nums1Size, n = nums2Size;
  int left = 0, right = m;

  while (left <= right) {
    int partitionA = (left + right) / 2;
    int partitionB = (m + n + 1) / 2 - partitionA;

    int maxLeftA = (partitionA == 0) ? INT_MIN : nums1[partitionA - 1];
    int minRightA = (partitionA == m) ? INT_MAX : nums1[partitionA];
    int maxLeftB = (partitionB == 0) ? INT_MIN : nums2[partitionB - 1];
    int minRightB = (partitionB == n) ? INT_MAX : nums2[partitionB];

    if (maxLeftA <= minRightB && maxLeftB <= minRightA) {
      if ((m + n) % 2 == 0) {
        return ((max(maxLeftA, maxLeftB) + min(minRightA, minRightB)) / 2.0);
      } else {
        return (max(maxLeftA, maxLeftB));
      }
    } else if (maxLeftA > minRightB) {
      right = partitionA - 1;
    } else {
      left = partitionA + 1;
    }
  }

  return (0.0);
}

int main(void) { return 0; }
