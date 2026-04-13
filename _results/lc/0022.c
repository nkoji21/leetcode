#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
backtrackでやる

openとcloseの数を管理しておく。
- open < n なら current[open+close] = '(' して再帰(open+1)
- close < open なら current[open+close] = ')' して再帰(close+1)
- ベースケースは open == close == nのとき、currentを答えの配列に追加(strdup関数)

答えの配列サイズ:
nが与えられた時点でカタラン数で確定できる。最大n=8で1430個。

currentの管理:
最初はstrcat + popを考えたけど、
indexで管理すれば次の分岐で同じ位置を上書きするだけだから
明示的なpopが不要になるのでよさそう
*/

// https://ja.wikipedia.org/wiki/%E3%82%AB%E3%82%BF%E3%83%A9%E3%83%B3%E6%95%B0
static int catalan(int n) {
  switch (n) {
    case 1:
      return 1;
    case 2:
      return 2;
    case 3:
      return 5;
    case 4:
      return 14;
    case 5:
      return 42;
    case 6:
      return 132;
    case 7:
      return 429;
    case 8:
      return 1430;
  }

  return 0;
}

typedef struct {
  char** result;
  int count;
  int n;
  char* current;
} Ctx;

static void backtrack(Ctx* ctx, int open, int close) {
  if (open == ctx->n && close == ctx->n) {
    ctx->current[2 * ctx->n] = '\0';
    ctx->result[ctx->count] = strdup(ctx->current);
    ctx->count++;
    return;
  }

  if (open < ctx->n) {
    ctx->current[open + close] = '(';
    backtrack(ctx, open + 1, close);
  }

  if (close < open) {
    ctx->current[open + close] = ')';
    backtrack(ctx, open, close + 1);
  }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** generateParenthesis(int n, int* returnSize) {
  Ctx ctx = {0};
  ctx.n = n;

  ctx.result = malloc(sizeof(*ctx.result) * catalan(n));
  ctx.current = malloc(sizeof(*ctx.current) * (2 * n + 1));
  if (ctx.result == NULL || ctx.current == NULL) return NULL;

  backtrack(&ctx, 0, 0);

  free(ctx.current);
  *returnSize = ctx.count;
  return ctx.result;
}

int main(void) {
  printf("Hello world!");
  return 0;
}
