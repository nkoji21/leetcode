#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

static inline int max(int a, int b) { return a < b ? b : a; }
static inline int min(int a, int b) { return a < b ? a : b; }

size_t getShortestStrLength(char **strs, int strsSize) {
  size_t min_len = INT_MAX;

  for (int i = 0; i < strsSize; i++) {
    size_t cur_len = 0;
    while (strs[i][cur_len] != '\0') {
      cur_len++;
    }

    min_len = min(min_len, cur_len);
  }

  return (min_len);
}

char *longestCommonPrefix(char **strs, int strsSize) {
  // 最短の文字列の長さを取得する
  size_t shortest_len = getShortestStrLength(strs, strsSize);

  // 取得したら、その長さ + 1分mallocする。 最後にヌル終端を入れることを忘れない
  char *prefix = malloc(sizeof(*prefix) * (shortest_len + 1));
  if (prefix == NULL)
    return (NULL);

  // その最短の文字列の長さまで繰り返す
  //  何個目かの文字列かのindex変数をstrsSizeまで繰り返す
  // si(str_idx) - 何個目かの文字列か, ci(char_idx) - 文字列の中の何文字目か
  for (size_t ci = 0; ci < shortest_len; ci++) {
    char target = strs[0][ci];
    for (size_t si = 1; si < (size_t)strsSize; si++) {
      if (strs[si][ci] != target) {
        prefix[ci] = '\0';
        return (prefix);
      }
    }

    prefix[ci] = target;
  }

  prefix[shortest_len] = '\0';
  return (prefix);
}

int main(int ac, char **av) {
  (void)ac;

  char *strs[] = {"dog", "racecar", "car"};
  int strsSize = 3;

  printf("%s\n", longestCommonPrefix(strs, strsSize));
  return 0;
}
