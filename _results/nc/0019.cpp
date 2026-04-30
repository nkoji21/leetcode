#include <bits/stdc++.h>
using namespace std;

/**
 * 文字の制約は uppercase and lowercase English letters.
 * 以下の情報を管理しておく 文字をcとする
 * - tに含まれるcの個数 (need[256]とか?)
 * - 今見てる区間に含まれるcの個数 (cnt[256]とか?)
 * - tの文字がそれぞれ何種類あるか (requiredとか)
 *   - requiredは初めて文字が登場した時、つまりneed[c] == 0の時にインクリメントする
 * - 今見てる区間の条件を満たした文字の種類数 (formedかな)
 *
 * 条件が成立したら、左端を詰める
 *  while(formed == required) の間、
 *  ans更新 -> 左端の文字を外す cnt[s[l]]--;
 *  -> 外した後に下のformedの条件で確認する
 *  -> l++;
 *
 * formedの動き方
 * - need[c] > 0 && cnt[c] == need[c] が成り立つときに formed++;
 * - need[c] > 0 && cnt[c] == need[c] - 1 になった場合は formed--;
 *
 * ans更新の方法だけど、
 * substrを使うと毎回コピーしちゃうから、最小幅の開始位置と長さを持っておけば
 * returnする時の1度のsubstrで出来そう。
 */
class Solution {
 public:
  string minWindow(string s, string t) {
    vector<int> need(256, 0), cnt(256, 0);

    // tの情報保存
    int required = 0;
    for (char c : t) {
      if (need[c - '0'] == 0) required++;
      need[c - '0']++;
    }

    // 尺取り法
    int l = 0, formed = 0, start = 0, minLen = INT_MAX;
    for (int r = 0; r < s.size(); r++) {
      int rc = s[r] - '0';

      cnt[rc]++;
      if (need[rc] > 0 && cnt[rc] == need[rc]) formed++;

      while (formed == required) {
        if (r - l + 1 < minLen) {
          minLen = r - l + 1;
          start = l;
        }

        int rl = s[l] - '0';
        cnt[rl]--;
        if (need[rl] > 0 && cnt[rl] == need[rl] - 1) formed--;

        l++;
      }
    }

    // 一度も更新されてない
    if (minLen == INT_MAX) return "";
    return s.substr(start, minLen);
  }
};

int main() {
  Solution solution;
  cout << solution.minWindow("a", "aa") << endl;
  return 0;
}
