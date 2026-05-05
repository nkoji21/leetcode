#include <bits/stdc++.h>
using namespace std;

/**
 * 思いついたのは、1つのスタック構造で
 * 2重ループでそれぞれの値をスタックに回していく方法かな。大きいのが見つかったら、それまでをpopして
 * 何回popできるかを出力する。
 *
 * けど、これだと計算量が O(n^2) かかりそうなのでTLEになると思う。
 *
 * ふぇてがMonotonic Stackって言ってたのと、Topicにもあるから調べてみる
 * ---
 *
 * 単調スタックとは、
 * スタックの中身が常に単調増加または単調減少になってるものらしい
 * 71 72 73 73 73 とか。
 *
 * 「次に〜となる日を求めて」とか、そういう時に使えるっぽい
 * O(N^2)が思いついた時にO(N)にできる方法
 */
class Solution {
 public:
  vector<int> dailyTemperatures(vector<int>& temperatures) {
    size_t n = temperatures.size();

    stack<int> st;
    vector<int> ans(n, 0);

    for (size_t i = 0; i < n; i++) {
      while (!st.empty() && temperatures[st.top()] < temperatures[i]) {
        ans[st.top()] = i - st.top();
        st.pop();
      }

      st.push(i);
    }

    return ans;
  }
};

int main() {
  Solution solution;
  vector<int> temps = {73, 74, 75, 71, 69, 72, 76, 73};

  vector<int> ans = solution.dailyTemperatures(temps);
  for (int& n : ans) {
    cout << n << ' ';
  }
  cout << endl;
  return 0;
}
