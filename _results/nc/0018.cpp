#include <bits/stdc++.h>
using namespace std;

/**
 * s1の各文字のカウントをカウントしておく
 *  - ハッシュ？ハッシュ使わない方法は、intの配列かな。
 * s2を走査しながら尺取り法で、s1の文字数とs2の区間のそれぞれの文字カウントが超えてなければtrue。
 */
class Solution {
 public:
  bool checkInclusion(const string& s1, const string& s2) {
    int n = s1.size(), m = s2.size();

    vector<int> freq(26, 0), window(26, 0);
    for (int i = 0; i < n; i++) {
      freq[s1[i] - 'a']++;
    }

    bool ok = false;
    int l = 0;
    for (int r = 0; r < m; r++) {
      int cr = s2[r] - 'a';
      window[cr]++;

      while (window[cr] > freq[cr] && l <= r) {
        window[s2[l] - 'a']--;
        l++;
      }

      if (r - l + 1 == n) ok = true;
    }

    return ok;
  }
};

int main() {
  Solution solution;
  cout << solution.checkInclusion("ab", "eidbaoooo") << endl;

  return 0;
}
