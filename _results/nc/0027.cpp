#include <bits/stdc++.h>
using namespace std;

class Solution {
  int binary_search(vector<int> &nums, int target) {
    int l = 0, r = static_cast<int>(nums.size()) - 1;
    while (l <= r) {
      int m = l + (r - l) / 2;
      if (nums[m] > target)
        r = m - 1;
      else if (nums[m] < target)
        l = m + 1;
      else
        return m;
    }

    return -1;
  }

public:
  int search(vector<int> &nums, int target) {
    return binary_search(nums, target);
  }
};

int main() {
  Solution solution;
  vector<int> nums = {-1, 0, 3, 5, 9, 12};
  cout << solution.search(nums, 9) << endl;

  return 0;
}
