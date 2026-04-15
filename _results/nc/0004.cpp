#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    int n = strs.size();
    vector<vector<string>> ans;

    // 文字列をソートして、その結果をキーにして、グループ化する
    unordered_map<string, vector<string>> group;
    for (int i = 0; i < n; i++) {
      string sorted_str = strs[i];
      sort(sorted_str.begin(), sorted_str.end());
      group[sorted_str].push_back(strs[i]);
    }

    // グループ化した結果をansに追加する
    for (auto& [k, v] : group) {
      ans.push_back(v);
    }

    return ans;
  }
};

int main() {
  Solution solution;
  vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
  vector<vector<string>> ans = solution.groupAnagrams(strs);
  for (auto& v : ans) {
    for (auto& s : v) {
      cout << s << " ";
    }
    cout << endl;
  }

  return 0;
}
