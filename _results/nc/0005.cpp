#include <bits/stdc++.h>
using namespace std;

/**
frequency sort: 頻度ソート

1, 1, 1, 2, 2, 3 という配列があったら、
1: 3
2: 2
3: 1 という頻度の配列になる

これをソートして、上位k個を返せば良い

これを O(n log n) で解くには
- 頻度をカウントする ハッシュを使う unordered_map<int, int> を使う
- 頻度でソートする
- 上位k個を返す
*/
class Solution {
 public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> cnt;
    for (int n : nums) {
      cnt[n]++;
    }

    vector<pair<int, int>> p;
    for (auto& [n, freq] : cnt) {
      p.push_back({freq, n});
    }

    sort(p.rbegin(), p.rend());

    vector<int> ans;
    for (int i = 0; i < k; ++i) {
      ans.push_back(p[i].second);
    }

    return ans;
  }
};

int main() {
  Solution solution;
  vector<int> nums = {1, 1, 1, 2, 2, 3};
  int k = 2;
  vector<int> ans = solution.topKFrequent(nums, k);
  for (int num : ans) {
    cout << num << " ";
  }
  cout << endl;
  return 0;
}
