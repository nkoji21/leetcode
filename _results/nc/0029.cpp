#include <bits/stdc++.h>
using namespace std;

/**
 * 「1時間あたり k 本のペースで、毎時間1つの山からだけバナナを食べていくとき、h
 * 時間以内に全部の山を食べ切れるような、最小の k を求める」
 *
 * 二分探索するのは、「kの値」
 * - kを決めた時に、それが条件を満たすかどうか
 *
 * 総和/時間で考えるのは違うみたい？
 * piles = [3,6,7,11] h = 8
 * 例えばk=3だとすると
 * 山1: 3本 -> 3/3 = 1時間
 * 山2: 6本 -> 6/3 = 2時間
 * 山3: 7本 -> 7/3 = 2.33 切り上げで3時間
 * 山4: 11本-> 11/3 = 3.666 切り上げで4時間
 *
 * これだと 10時間かかるから k=3は遅すぎる
 *
 *
 * 答えで二分探索をする場合に left right ってどう決めるべきなのか。
 * まずkは「1時間あたり何本食べるか」だから、
 * - 最小値(left)
 *   0だと一生食べ終わらないから、1やな
 *   left = 1
 * - 最大値(right)
 *   一番早く食べるとしたら、「1時間でどの山でも一気に食べ切れる」だから、
 *   最もでかい山のサイズ。
 *   right = max(piles)
 */
class Solution {
public:
  int minEatingSpeed(const vector<int> &piles, int h) {
    int left = 1;
    int right = *max_element(piles.begin(), piles.end());
    int ans = right;

    auto canEat = [&](int k) {
      long long hours = 0;
      for (int p : piles) {
        hours += (p + k - 1) / k; // 切り上げ
      }
      return hours <= h;
    };

    while (left <= right) {
      int mid = left + (right - left) / 2;

      if (canEat(mid)) {
        ans = mid;
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }

    return ans;
  }
};

int main() {
  Solution solution;
  cout << solution.minEatingSpeed({3, 6, 7, 11}, 8) << endl;
  return 0;
}
