#include <bits/stdc++.h>
using namespace std;

/**
 * 出現頻度の低い文字を、置き換えたい
 * 区間 - 最も頻繁に出現する文字の数 <= k の間は区間が成り立つ
 *
 * 区間を拡張しながらこれらを見ておく
 * - 各文字の出現回数 (頻度 = frequency)
 * - 区間内で最も頻繁に出現する文字
 *
 * 区間が成り立たなくなったら、左を詰める
 */
class Solution {
 public:
  int characterReplacement(const string& s, int k) {
    vector<int> freq(26);
    int maxLength = 0;

    int l = 0, maxFreq = 0;
    for (int r = 0; r < s.size(); r++) {
      int idx = s[r] - 'A';
      freq[idx]++;
      maxFreq = max(maxFreq, freq[idx]);

      // 区間が成り立たなくなったら
      while ((r - l + 1) - maxFreq > k) {
        freq[s[l] - 'A']--;
        l++;
      }

      maxLength = max(maxLength, r - l + 1);
    }

    return maxLength;
  }
};

int main() {
  Solution solution;
  cout << solution.characterReplacement("ABAB", 2) << endl;

  return 0;
}
