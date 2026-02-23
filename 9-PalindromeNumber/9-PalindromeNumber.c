// Last updated: 2/23/2026, 5:06:15 PM
static bool is_palindrome_by_half_reverse(int x) {
    int reversedLowerHalf = 0;

    while (x > reversedLowerHalf) {
        reversedLowerHalf = reversedLowerHalf * 10 + (x % 10);
        x /= 10;
    }

    // 桁数が偶数か奇数
    return (x == reversedLowerHalf || x == reversedLowerHalf / 10);
}

bool isPalindrome(int x) {
    if (x < 0)
        return false;

    // 10の倍数で0以外回文ではない
    if (x != 0 && x % 10 == 0)
        return false;

    return (is_palindrome_by_half_reverse(x));
}