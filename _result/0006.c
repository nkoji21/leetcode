#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *convert(char *s, int numRows) {
  size_t s_len = strlen(s);
  char *zigzag = malloc(s_len * sizeof(*zigzag) + 1);
  if (!zigzag)
    return (NULL);

  if (numRows == 1)
    return (memcpy(zigzag, s, s_len + 1), zigzag);

  char *p = zigzag;
  int step = 2 * (numRows - 1);
  for (int row = 0; row < numRows; row++) {
    for (int count = row; count < (int)s_len; count += step) {
      *p++ = s[count];
      if (row > 0 && row < numRows - 1) {
        int j = count + step - 2 * row;
        if (j < (int)s_len)
          *p++ = s[j];
      }
    }
  }

  *p = '\0';
  return (zigzag);
}

int main(int ac, char **av) {
  (void)ac;

  printf("%s\n", av[1]);
  return 0;
}
