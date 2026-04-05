#include <stdbool.h>
#include <stdio.h>
#include <string.h>

/**
スタック構造かな

'(', ')', '{', '}', '[' and ']'

(, {, [ ならスタックに入れて、
閉じかっこなら出していく。けどその時に、同じ種類のカッコじゃないと出せないようにする

で、最後にカウントする？
それとも、スタックの作業しながら現在入ってる数を保持しておいて、最後に0なら、true みたいな感じかな
*/

bool isValid(char* s) {
  size_t n = strlen(s);
  char stack[n];

  int top = -1;
  for (size_t i = 0; i < n; i++) {
    if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
      stack[++top] = s[i];
    }

    if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
      if (top == -1) return false;
      char popped = stack[top--];

      if ((s[i] == ')' && popped != '(') || (s[i] == '}' && popped != '{') ||
          (s[i] == ']' && popped != '['))
        return false;
    }
  }

  return (top == -1);
}

int main(void) {
  printf("%d\n", isValid("()[]{}"));
  return 0;
}
