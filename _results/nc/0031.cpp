#include <bits/stdc++.h>
using namespace std;

/**
 * ソート済み + 回転済み
 * つまり、昇順のブロックが2つある。
 *
 * targetの値があった場所のインデックスを返す
 * もし無かったら-1を返す。
 *
 * nums[left] <= nums[mid] なら、left..mid が昇順ブロック
 * -> その中にtargetがあるかどうか
 *   -> nums[left] <= target && target < nums[mid] なら
 *   -> right = mid - 1にする。
 *   -> そうじゃないなら left = mid + 1
 *
 * それ以外なら右半分が mid..right が昇順ブロック
 * 右ブロックにtargetがいるかを判定させる
 *
 * 整理すると、
 * 1. nums[left] <= nums[mid] なら左半分が昇順
 * 2. そうでなければ右半分が昇順
 * 3. 1か2のどちらかにtargetがはいるならそちらへ絞る
 * 4. 入らないなら反対側へ絞る
 */
class Solution {
public:
  int search(vector<int> &nums, int target) {
    int left = 0, right = (int)nums.size() - 1;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (nums[mid] == target)
        return mid;
      if (nums[left] <= nums[mid]) {
        // 左半分 left..mid が昇順
        if (nums[left] <= target && target < nums[mid]) {
          right = mid;
        } else {
          left = mid + 1;
        }
      } else {
        // 右半分 mid..right が昇順
        if (nums[mid] < target && target <= nums[right]) {
          left = mid + 1;
        } else {
          right = mid;
        }
      }
    }
    return -1;
  }
};

int main() {
  Solution solution;
  vector<int> nums = {1};
  cout << solution.search(nums, 1) << endl;
  return 0;
}
