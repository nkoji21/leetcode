#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
連続する文字列の最大の長さを返せば良い？
abcdなら4かな

a~zの26個分のint型の配列を作って、入力の文字列を最初から走査して
見つけたascii番目を+1する ->
もしどこかで2になったのならそこで結果のlenを更新する
-> 配列の数字を全て0に戻す -> そこからまた走査

これを最後までやれば良いかな？
繋がってる文字列を見ればいいから計算量は O(n)かな?

やること
- a~z個分の配列をcallocを使って、ゼロ値で初期化する
- 全部0にクリアする作業
  - callocしてあったものはfreeして、またcallocする?

入力は
- English letters
- digits
- symbols and spaces らしい。

a~z分じゃなくて、asciiの127個分の配列作るか

重複した文字が、ウィンドウのどこにあるかをインデックスで保持しておく必要ある？
dvdfとかの時、dvdまで見たあと、vdから始めれるように90

---
違うわ、一度見た場所をlast_seenだとして
last_seenを全て-1にする (indexが0からなため。未出現だったら-1)
last_seenには、それが見つかった場所のindexを入れる

last_seen[idx] >= startで、その文字が今の区間[start, 今の位置]の中にある
-> 同じ文字が2回あるから重複してる
last_seen == -1 の「まだ見てない」ケースは弾ける
*/

int lengthOfLongestSubstring(char *s) {
  int answer = 0, len = 0;
  int start = 0;
  char *cur = s;

  size_t ascii = 127;
  int *last_seen = malloc(sizeof(*last_seen) * ascii);
  if (!last_seen)
    return (-1);

  while (*cur != '\0') {
    size_t idx = (size_t)*cur;
    size_t pos = cur - s;

    if (last_seen[idx] >= start) {
      start = last_seen[idx] + 1;
    }
    last_seen[idx] = pos;

    len = pos - start + 1;
    if (answer < len)
      answer = len;

    cur++;
  }

  free(last_seen);
  return (answer);
}

int main(int ac, char **av) {
  (void)ac;

  printf("%d\n", lengthOfLongestSubstring(av[1]));
  return (0);
}
