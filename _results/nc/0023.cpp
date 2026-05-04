#include <bits/stdc++.h>
using namespace std;

/**
 * 数値ならスタックに格納する
 * 演算子なら上から2つを取り出して、計算する
 *
 * 制約気にしたい
 * - 演算子は + - * / の4つ
 * - 0による徐算は行わない
 * - 徐算は切り捨て
 * - 答えは32bitの範囲になるようになってるらしい。
 */
class Solution {
 public:
  int evalRPN(vector<string>& tokens) {
    stack<int> st;

    for (const string& tk : tokens) {
      if (tk == "+" || tk == "-" || tk == "*" || tk == "/") {
        int a = st.top();
        st.pop();
        int b = st.top();
        st.pop();

        if (tk == "+")
          st.push(b + a);
        else if (tk == "-")
          st.push(b - a);
        else if (tk == "*")
          st.push(b * a);
        else
          st.push(b / a);
      } else {
        st.push(stoi(tk));
      }
    }

    return st.top();
  }
};

int main() {
  Solution solution;
  vector<string> tokens = {"2", "1", "+", "3", "*"};

  cout << solution.evalRPN(tokens) << endl;
  return 0;
}
