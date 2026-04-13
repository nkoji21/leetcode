#include <stdlib.h>
#include <string.h>

static void expand(char *s, int left, int right, int *start, int *max_len) {
  int len;

  while (left >= 0 && s[right] != '\0' && s[left] == s[right]) {
    len = right - left + 1;
    if (len > *max_len) {
      *max_len = len;
      *start = left;
    }
    left--;
    right++;
  }
}

char *longestPalindrome(char *s) {
  int n = strlen(s);

  int start = 0;
  int max_len = 1;
  for (int i = 0; s[i] != '\0'; i++) {
    expand(s, i, i, &start, &max_len);
    expand(s, i, i + 1, &start, &max_len);
  }

  char *result = (char *)malloc(max_len + 1);
  if (!result)
    return NULL;

  strncpy(result, s + start, max_len);
  result[max_len] = '\0';
  return result;
}

int main(void) {}
