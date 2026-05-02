#include <bits/stdc++.h>
using namespace std;

/**
 * 先頭が常に降順になるように値のインデックスを格納してみる
 *
 * 尺取り法としてrightを進めていって、
 * 末端のインデックス番目と、次のrightの値を比べて、次の方が大きいのなら
 * 末端のものはずっと最大値になることはないから、捨てる。
 *
 * 上のが通過したら、データ構造にインデックスを追加していく。
 *
 * leftがデータ構造の先端より大きくなれば先端の値を削除する。
 * r+1がk以上になったら、区間を一つずつずらしていくから、l++; していく。
 */
class Solution {
 public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> ans;
    deque<int> dq;

    int l = 0, r = 0;
    while (r < nums.size()) {
      while (!dq.empty() && nums[dq.back()] < nums[r]) {
        dq.pop_back();
      }

      dq.push_back(r);

      if (l > dq.front()) {
        dq.pop_front();
      }

      if (r + 1 >= k) {
        ans.push_back(nums[dq.front()]);
        l++;
      }

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
