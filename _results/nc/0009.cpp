#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int longestConsecutive(vector<int>& nums) {
    if (nums.empty()) return 0;

    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());

    int cnt = 1, ans = 1;
    for (size_t i = 0; i < nums.size() - 1; i++) {
      if (nums[i] + 1 == nums[i + 1]) {
        cnt++;
      } else {
        cnt = 1;
      }

      ans = max(ans, cnt);
    }

    return ans;
  }
};

int main() {
  Solution solution;

  vector<int> nums = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};

  cout << solution.longestConsecutive(nums) << endl;
  return 0;
}
