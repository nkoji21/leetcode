#include <bits/stdc++.h>
using namespace std;

/**
 * hashmapで、それぞれの文字の出現インデックスを管理
 * もし重複してるものがあったら、leftをその出現インデックスの値にする
 */
class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    if (s.empty()) return 0;

    int ans = 0, l = 0, r = 0;

    unordered_map<char, int> seen;
    while (r < s.size()) {
      if (seen.count(s[r]) > 0 && seen[s[r]] >= l) {
        l = seen[s[r]] + 1;
      }
      seen[s[r]] = r;
      ans = max(ans, r - l + 1);
      r++;
    }
    return ans;
  }
};

int main() {
  Solution solution;
  cout << solution.lengthOfLongestSubstring("pwwkew") << endl;

  return 0;
}
