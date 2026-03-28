#include <stdio.h>
#include <string.h>

static const struct {
  char symbol;
  int value;
} roman_map[] = {
    {'I', 1},   {'V', 5},   {'X', 10},   {'L', 50},
    {'C', 100}, {'D', 500}, {'M', 1000},
};

static int roman_value(char c) {
  for (size_t i = 0; i < sizeof(roman_map) / sizeof(roman_map[0]); i++) {
    if (roman_map[i].symbol == c)
      return (roman_map[i].value);
  }

  return (0);
}

int romanToInt(char *s) {
  int total = 0;

  size_t s_len = strlen(s);
  for (size_t i = 0; i < s_len; i++) {
    int cur = roman_value((s[i]));
    int next = (i + 1 < s_len) ? roman_value(s[i + 1]) : 0;

    total += (cur < next) ? -cur : cur;
  }

  return (total);
}

int main(int ac, char **av) {
  (void)ac;

  printf("%s\n", av[1]);
  return 0;
}
