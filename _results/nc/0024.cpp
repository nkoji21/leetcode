#include <bits/stdc++.h>
using namespace std;

/**
 * DPで解けそう
 */
class Solution {
 public:
  vector<int> dailyTemperatures(vector<int>& temperatures) {
    size_t n = temperatures.size();
    vector<int> ans(n, 0);

    for (int i = n - 2; i >= 0; i--) {
      int j = i + 1;
      while (j < n && temperatures[j] <= temperatures[i]) {
        if (ans[j] == 0) {
          j = n;
          break;
        }

        j += ans[j];
      }

      if (j < n) {
        ans[i] = j - i;
      }
    }

    return ans;
  }
};

int main() {
  Solution solution;
  vector<int> temps = {73, 74, 75, 71, 69, 72, 76, 73};

  vector<int> ans = solution.dailyTemperatures(temps);
  for (int n : ans) {
    cout << n << ' ';
  }
  cout << endl;
  return 0;
}
