#include <bits/stdc++.h>
using namespace std;

/**
 * 売るためには買っておかないといけない。
 * どこで買うか、どこで売るかシミュレーションして、最大の利益が出る売買を探す
 *
 * sliding windowなら、
 *
 */
class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int l = 0, r = 1;
    int maxP = 0;

    while (r < prices.size()) {
      if (prices[l] < prices[r]) {
        int profit = prices[r] - prices[l];
        maxP = max(maxP, profit);
      } else {
        l = r;
      }
      r++;
    }
    return maxP;
  }
};

int main() {
  Solution solution;
  vector<int> prices = {7, 1, 5, 3, 6, 4};

  cout << solution.maxProfit(prices) << endl;
  return 0;
}
