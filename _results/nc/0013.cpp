#include <bits/stdc++.h>
using namespace std;

/**
左と右の2点を持っておいて、height[l] < height[r] ならl++
height[l] > height[r] ならr-- かな?

その中で、(r - l) * min(height[l], height[r])で、面積を毎回求めながら
最大を更新していく感じで、最後に出力かな
*/
class Solution {
 public:
  int maxArea(vector<int>& height) {
    int maxArea = 0;

    int l = 0, r = height.size() - 1;
    while (l < r) {
      maxArea = max(maxArea, (r - l) * min(height[l], height[r]));
      height[l] < height[r] ? l++ : r--;
    }

    return maxArea;
  }
};

int main() {
  Solution solution;

  vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
  cout << solution.maxArea(height) << endl;
  return 0;
}
