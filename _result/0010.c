#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**

| | "" | "a" | "a*" |
| "" | T | F | T |
| "a" | F | T | T |
| "aa" | F | F | T |

dp[1][2] = T
dp[i][j] = dp[i][j - 2] || (文字が合う && dp[i - 1][j]);
-> dp[1][0] = F
-> 文字は合う "a" == "a"
-> dp[0][2] = T
dp[1][2] = dp[1][0] || TRUE && dp[0][2]

x* = 「xを0回以上繰り返して良い」=> 0回使う場合と、1回以上使う場合に分けて考える

dp[i][j]:
sの先頭i文字目とpの先頭j文字目がマッチしているか

最終的に右下のdp[s_len][p_len]の結果を見れば良き
*/

static bool char_match(char sc, char pc) { return (pc == '.' || pc == sc); }

bool isMatch(char *s, char *p) {
  // sとpの長さを取る
  // dpのサイズを決めるために必要
  size_t s_len = strlen(s);
  size_t p_len = strlen(p);

  // (s_len + 1) * (p_len + 1) の表を作る
  // dpは前の値を見るから、0文字目を入れるために +1する
  bool **dp = malloc(sizeof(*dp) * (s_len + 1));
  if (dp == NULL)
    return (false);

  for (size_t i = 0; i <= s_len; i++) {
    dp[i] = malloc(sizeof(*dp[i]) * (p_len) + 1);
    if (dp[i] == NULL) {
      while (i-- >= 0)
        free(dp[i]);
      free(dp);
      return (false);
    }
    memset(dp[i], 0, (p_len + 1) * sizeof(*dp[i]));
  }

  // 空文字同士はマッチさせる dp[0][0] = true
  // それ以外はfalseから始める
  dp[0][0] = true;

  // sが空文字の時、pが空文字にマッチするときを埋める
  // p[j-1] == '*' なら、
  // x* を 0回使って、dp[i][j] = dp[i][j-2]
  for (size_t j = 2; j <= p_len; j++) {
    if (p[j - 1] == '*')
      // '*'の直前の文字が一致してたらtrueが入り、してなければfalseが入る
      dp[0][j] = dp[0][j - 2];
  }

  for (size_t i = 1; i <= s_len; i++) {
    for (size_t j = 1; j <= p_len; j++) {
      if (p[j - 1] != '*') {
        //  もし p[j-1] が普通の文字または'.'の場合
        if (char_match(s[i - 1], p[j - 1]))
          // 1文字前の結果を引き継げる
          dp[i][j] = dp[i - 1][j - 1];
      } else {
        // '*' の場合
        // x* を0回使う場合
        dp[i][j] = dp[i][j - 2];

        // x* を1回以上使う場合
        // p[j-2]がs[i-1]と一致するなら
        if (j >= 2 && char_match(s[i - 1], p[j - 2]))
          dp[i][j] |= dp[i - 1][j];
      }
    }
  }

  bool result = dp[s_len][p_len];

  for (size_t i = 0; i <= s_len; i++)
    free(dp[i]);
  free(dp);

  return (result);
}

int main(void) {
  printf("%d\n", isMatch("aa", "a"));      // false
  printf("%d\n", isMatch("aa", "a*"));     // true
  printf("%d\n", isMatch("ab", ".*"));     // true
  printf("%d\n", isMatch("aab", "c*a*b")); // true

  return 0;
}
