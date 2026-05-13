#include <bits/stdc++.h>
using namespace std;

/**
 * みはじ虫ですな
 * 距離 = target - position[i]
 * 速さ = speed[i]
 * 時間 = 距離/速さ (doubleにする)
 *
 * 1. (position, speed) をposition降順に並べる
 * 2. 各車の time = (target - position[i])/speed を出す
 * 3. positionが高い順に、つまりゴール側からスタート側に走査して、
 *    time がこれまでのmaxTimeより大きい時だけ、新しいfleetとしてカウント
 *    time <= maxTime なら、どこかで既存のfeetに追いつくからカウントしない
 */
class Solution {
public:
  int carFleet(int target, vector<int> &position, vector<int> &speed) {
    vector<pair<int, int>> cars;

    for (int i = 0; i < position.size(); i++) {
      cars.push_back({position[i], speed[i]});
    }
    sort(cars.rbegin(), cars.rend());

    stack<double> st;

    for (auto [p, s] : cars) {
      double t = (double)(target - p) / s;

      if (st.empty() || t > st.top()) {
        st.push(t);
      }
    }
    return st.size();
  }
};

int main() {
  Solution solution;
  return 0;
}

