#include <bits/stdc++.h>
using namespace std;

/**
愚直な解法:
全ての要素を走査しながら、その要素と同じ値があればtrueを返す O(N^2)

より良い解法:
ソートして、隣り合う要素を比較して、同じ値があればtrueを返す O(N log N)

最適な解法:
ハッシュマップを使って、要素を走査して、同じ値があればtrueを返す O(N)

スピードとメモリのトレードオフかな
ハッシュマップは、重複が少ないほどメモリを多く食うし
ソートはメモリはほぼ定数だけど、若干スピード遅いし
*/
class Solution {
 public:
  bool containsDuplicate(vector<int> &nums) {
    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size() - 1; i++) {
      if (nums[i] == nums[i + 1]) return true;
    }
    return false;
  }
};

int main() {
  Solution solution;
  vector<int> nums = {1, 1, 3, 4, 5};

  cout << solution.containsDuplicate(nums) << endl;
  return 0;
}
