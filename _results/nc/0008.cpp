#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  bool isValidSudoku(vector<vector<char>>& board) {
    int n = 9;

    // 横の重複チェック
    for (int r = 0; r < n; r++) {
      vector<int> cnt(n, 0);
      for (int c = 0; c < n; c++) {
        char cur = board[r][c];

        if (cur == '.') continue;
        cur -= '1';

        if (cnt[cur] > 0) return false;
        cnt[cur]++;
      }
    }

    // 縦の重複チェック
    for (int c = 0; c < n; c++) {
      vector<int> cnt(n, 0);
      for (int r = 0; r < n; r++) {
        char cur = board[r][c];

        if (cur == '.') continue;
        cur -= '1';

        if (cnt[cur] > 0) return false;
        cnt[cur]++;
      }
    }

    /**
      iが左上から何個目の3x3かで、
      3*i+jとkで、board[j][k] やればいいかな?
      それぞれjとkは、j%3とk%3?
    */
    for (int br = 0; br < 3; br++) {
      for (int bc = 0; bc < 3; bc++) {
        vector<int> cnt(n, 0);
        for (int i = 0; i < 3; i++) {
          for (int j = 0; j < 3; j++) {
            int r = 3 * br + i;
            int c = 3 * bc + j;
            char cur = board[r][c];

            if (cur == '.') continue;
            cur -= '1';

            if (cnt[cur] > 0) return false;
            cnt[cur]++;
          }
        }
      }
    }

    return true;
  };
};

int main() {
  Solution solution;

  vector<vector<char>> board = {
      {'5', '3', '.', '.', '7', '.', '.', '.', '.'}, {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
      {'.', '9', '8', '.', '.', '.', '.', '6', '.'}, {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
      {'4', '.', '.', '8', '.', '3', '.', '.', '1'}, {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
      {'.', '6', '.', '.', '.', '.', '2', '8', '.'}, {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
      {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

  cout << solution.isValidSudoku(board) << endl;

  return 0;
}
