#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> ans;
    int tmp = INT_MIN;

    int l = 0, r = 0;
    while (r < k) {
      tmp = max(tmp, nums[r]);
      r++;
    }

    ans.push_back(tmp);

    while (r < nums.size()) {
      if (tmp < nums[r]) {
        tmp = nums[r];
      }

      ans.push_back(tmp);

      l++;
      r++;
    }

    return ans;
  }
};

int main() {
  Solution solution;
  vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};

  vector<int> ans = solution.maxSlidingWindow(nums, 3);

  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << ' ';
  }
  cout << endl;

  return 0;
}
