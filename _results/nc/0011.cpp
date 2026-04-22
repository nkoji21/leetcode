#include <bits/stdc++.h>
using namespace std;

/**
ソートされてる数字の配列の中から 2個の数字を足して
targetになるものを探す (index+1)

target - numbers[i] を探せば良さそう (ソートされてるし、二分探索で良いかな)
見つかった時点で終了だけど、iをnumbers.size()分回して、その中で二分探索で値を見つけるから、最悪がO(N*logN)なのかな？

二分探索
- lとrとmを持っておいて、mがその値ならreturnしちゃう
- mの値がneedより大きいんだったら、rはm-1、右端を縮小する
- mの値がneedより小さいんだったら、lはm+1、左端を縮小する
*/
class Solution {
 public:
  vector<int> twoSum(vector<int>& numbers, int target) {
    int n = numbers.size();
    for (int i = 0; i < n; i++) {
      int need = target - numbers[i];

      int l = i + 1, r = n - 1;
      while (l <= r) {
        int m = (l + r) / 2;
        if (numbers[m] == need) {
          return {i + 1, m + 1};
        }

        if (numbers[m] > need) r = m - 1;
        if (numbers[m] < need) l = m + 1;
      }
    }
    return {};
  }
};

int main() {
  Solution solution;
  vector<int> numbers = {-1, 0};
  int target = -1;

  vector<int> ans = solution.twoSum(numbers, target);
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << ' ';
  }
  cout << endl;

  return 0;
}
