#include <bits/stdc++.h>
using namespace std;

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
    int leftMax = height[l], rightMax = height[r];
    while (l < r) {
      if (leftMax < rightMax) {
        l++;
        leftMax = max(leftMax, height[l]);
        ans += leftMax - height[l];
      } else {
        r--;
        rightMax = max(rightMax, height[r]);
        ans += rightMax - height[r];
      }
    }

    return ans;
  }
};

int main() {
  Solution soluiton;
  vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  cout << soluiton.trap(height) << endl;
  return 0;
}
