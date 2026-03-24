#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool is_palindrome_by_half_reverse(int x) {
  int reversedLowerHalf = 0;

  while (x > reversedLowerHalf) {
    reversedLowerHalf = reversedLowerHalf * 10 + (x % 10);
    x /= 10;
  }

  return (x == reversedLowerHalf || x == reversedLowerHalf / 10);
}

bool isPalindrome(int x) {
  if (x < 0 || (x != 0 && x % 10 == 0))
    return (false);

  return (is_palindrome_by_half_reverse(x));
}

int main(int ac, char **av) {
  (void)ac;

  printf("%d\n", isPalindrome(atoi(av[1])));
  return 0;
}
