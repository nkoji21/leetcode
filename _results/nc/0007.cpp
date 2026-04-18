#include <bits/stdc++.h>
using namespace std;

/**
全ての値を乗算しておいて、その結果をnums[i]で割る
zerocount が 1より大きいのなら、全ての答えは0になる

答えはint型の範囲であることが保証されてるみたい
*/
class Solution {
 public:
  vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();

    int p = 1, zc = 0;
    for (int x : nums) {
      if (x != 0) {
        p *= x;
      } else {
        zc++;
      }
    }

    if (zc > 1) {
      return vector<int>(n, 0);
    }

    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
      if (zc > 0) {
        ans[i] = (nums[i] == 0) ? p : 0;
      } else {
        ans[i] = p / nums[i];
      }
    }

    return ans;
  }
};

int main() {
  Solution solution;

  vector<int> nums = {-1, 1, 0, -3, 3};

  vector<int> ans = solution.productExceptSelf(nums);
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << ' ';
  }
  cout << endl;
  return 0;
}
