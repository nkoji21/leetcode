#include <bits/stdc++.h>
using namespace std;

/**
 * 単調増加スタックで解く。
 *
 * st には (その高さの長方形を開始できる一番左の index, height) を積む。
 * 例: (2, 5) は「高さ 5 の長方形は index 2 から開始できる」という意味。
 *
 * 左から右へ見ていき、今の棒が stack の top より低くなったら、
 * top の高さは「今の位置 i ではもう右に伸ばせない」ことが確定する。
 * そのため height * (i - index) で面積を計算する。
 */
class Solution {
public:
  int largestRectangleArea(const vector<int> &heights) {
    int maxArea = 0;
    stack<pair<int, int>> st; // (index, height)

    for (int i = 0; i < heights.size(); i++) {
      // 今の高さ heights[i] が、どこまで左に広がれるか。
      // 基本は自分自身の位置から開始する。
      int start = i;

      // stack は高さが単調増加になるように保つ。
      // 今の棒より高い棒は、今の位置 i で右への伸びが止まるので面積を確定する。
      while (!st.empty() && st.top().second > heights[i]) {
        pair<int, int> top = st.top();
        int index = top.first;
        int height = top.second;

        // index から i - 1 までの幅で、高さ height の長方形を作れる。
        maxArea = max(maxArea, height * (i - index));

        // pop した高さより今の高さの方が低いので、
        // 今の高さは pop した棒の開始位置まで左に広がれる。
        start = index;
        st.pop();
      }

      // 今の高さを、左に広がれる開始位置 start と一緒に積む。
      st.push({start, heights[i]});
    }

    // 最後まで stack に残った棒は、配列の右端まで伸ばせる。
    while (!st.empty()) {
      int index = st.top().first;
      int height = st.top().second;
      maxArea =
          max(maxArea, height * (static_cast<int>(heights.size()) - index));
      st.pop();
    }

    return maxArea;
  }
};

int main() {
  Solution solution;
  cout << solution.largestRectangleArea({2, 1, 5, 6, 2, 3}) << endl;
  return 0;
}
