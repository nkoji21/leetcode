#include <bits/stdc++.h>
using namespace std;

/**
1. 全ての文字のカウントを数える
2. 2つの文字列をソートして、同じ文字列になっているかを確認する
*/
class Solution {
 public:
  bool isAnagram(string s, string t) {
    if (s.size() != t.size()) return false;

    unordered_map<char, int> cnt;
    for (char c : s) cnt[c]++;
    for (char c : t) {
      cnt[c]--;
      if (cnt[c] < 0) return false;
    }
    return true;
  }
};

int main() {
  Solution solution;
  cout << solution.isAnagram("ab", "a") << endl;
  return 0;
}
