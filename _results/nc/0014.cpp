#include <bits/stdc++.h>
using namespace std;

/**
leftMax, rightMaxとして左右の壁の最も大きかった壁の高さを保持しておく
これで水面の高さを求めることができる
*/
class Solution {
 public:
  int trap(vector<int>& height) {
    int ans = 0;

    int l = 0, r = height.size() - 1;
    int lM = height[l], rM = height[r];
    while (l < r) {
      if (lM < rM) {
        l++;
        lM = max(lM, height[l]);
        ans += lM - height[l];
      } else {
        r--;
        rM = max(rM, height[r]);
        ans += rM - height[r];
      }
    }

    return ans;
  }
};

int main() {
  Solution solution;

  vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  cout << solution.trap(height) << endl;
  return 0;
}
