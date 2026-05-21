#include <bits/stdc++.h>
using namespace std;

/**
 * setは普通に操作を実装して、getは二分探索で見つける感じかな？
 * ["foo", 3] の時に "bar" が帰ってくるのわからんな。
 * timestamp=1にbarをセットしてるんじゃないっけ？
 *
 * あー、get("foo", 3) ってことは3以下の履歴を探すのか。
 * 「過去ログを遡って、一番ん最近の値を取ってくる辞書」てきな感じか
 */
class TimeMap {
public:
  TimeMap() {}

  void set(string key, string value, int timestamp){a} string
      get(string key, int timestamp) {}
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */

int main() {
  TimeMap timeMap;

  timeMap.set("foo", "bar", 1);
  assert(timeMap.get("foo", 1) == "bar");
  assert(timeMap.get("foo", 3) == "bar");

  timeMap.set("foo", "bar2", 4);
  assert(timeMap.get("foo", 4) == "bar2");
  assert(timeMap.get("foo", 5) == "bar2");

  return 0;
}
