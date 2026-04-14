#include <bits/stdc++.h>
using namespace std;

/**
 * Two Sum: 値 -> その値が最後に出たインデックス を unordered_map に保持する。
 * 例: nums = [2,7,11,15], target = 9
 * - i=0: r=7。7 は未登録なので map[2]=0 を保存。
 * - i=1: r=2。2 は map にあり index 0 → 答えは {0,1}。
 */
class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> remaining;
    for (int i = 0; i < nums.size(); ++i) {
      int r = target - nums[i];
      if (remaining.contains(r)) {
        return {remaining[r], i};
      } else {
        remaining[nums[i]] = i;
      }
    }

    return {};
  }
};

int main() {
  Solution solution;
  vector<int> nums = {2, 7, 11, 15};
  int target = 9;
  vector<int> ans = solution.twoSum(nums, target);
  cout << ans[0] << " " << ans[1] << endl;
  return 0;
}
