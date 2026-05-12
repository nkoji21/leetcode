#include <bits/stdc++.h>
using namespace std;

/**
 * 1. 行を決める二分探索をする
 *  - 前の行の最後の要素 < 次の行の最初の要素 が成り立つ
 * 2. 行の中でtargetを二分探索する
 *
 * いや、上の方法でもいけると思うけどちょっとチャレンジに
 * 2次元を1次元として探索もできるよな
 */
class Solution {
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    int m = matrix.size();
    int n = matrix[0].size();

    int l = 0, r = m * n - 1;
    while (l <= r) {
      int p = l + (r - l) / 2;
      int v = matrix[p / n][p % n];

      if (v < target) {
        l = p + 1;
      } else if (v > target) {
        r = p - 1;
      } else {
        return true;
      }
    }

    return false;
  }
};

int main() {
  Solution solution;
  vector<vector<int>> mtx = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
  cout << solution.searchMatrix(mtx, 3) << endl;
  return 0;
}
