#include <bits/stdc++.h>
using namespace std;

/**
 * ソート済みで回転してるってことは、
 * 2つの昇順ブロックがくっついてるだけと考えれる
 *
 * 例えば、{3,4,5,1,2}なら{3,4,5}と{1,2}でしょ
 */
class Solution {
public:
  int findMin(vector<int> &nums) {
    int left = 0, right = (int)nums.size() - 1;
    while (left < right) {
      int mid = left + (right - left) / 2;

      if (nums[mid] > nums[right]) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }

    return nums[left];
  }
};

int main() {
  Solution solution;
  vector<int> nums = {3, 4, 5, 1, 2};
  cout << solution.findMin(nums) << endl;
  return 0;
}
