#include <bits/stdc++.h>

#include <cctype>
using namespace std;

class Solution {
 public:
  bool isPalindrome(string s) {
    // 大文字なら小文字にし、英字以外ならスキップする
    string t;

    for (char c : s) {
      if (!isalnum(c)) continue;
      if (isupper(c)) c += 32;
      t.push_back(c);
    }

    // 回文かどうか
    int n = t.size();
    for (int i = 0; i < n / 2; i++) {
      if (t[i] != t[n - 1 - i]) {
        return false;
      }
    }

    return true;
  }
};

int main() {
  Solution solution;
  string s = " ";

  cout << solution.isPalindrome(s) << endl;
  return 0;
}
