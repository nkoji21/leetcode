#include <bits/stdc++.h>
using namespace std;

/**
 * スタック構造で、開きカッコを入れて
 * 閉じカッコの時に同じ種類の開きカッコだったら取る
 *
 * 最後にデータ構造に何か残ってればfalse
 * 確かCppにスタック構造あった気がする
 * push() pop() top() で使える
 */
class Solution {
 public:
  bool isValid(string s) {
    stack<char> st;

    for (char c : s) {
      if (c == '(' || c == '{' || c == '[') {
        st.push(c);
      } else {
        if (st.empty()) return false;

        char top = st.top();
        st.pop();

        if ((c == ')' && top != '(') || (c == '}' && top != '{') || (c == ']' && top != '[')) {
          return false;
        }
      }
    }

    return st.empty();
  }
};

int main() {
  Solution solution;
  cout << solution.isValid("()[]{}") << endl;
  return 0;
}
