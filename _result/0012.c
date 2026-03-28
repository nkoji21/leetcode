#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static const struct {
  int value;
  const char *symbol;
} roman_map[] = {
    {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"},
    {90, "XC"},  {50, "L"},   {40, "XL"}, {10, "X"},   {9, "IX"},
    {5, "V"},    {4, "IV"},   {1, "I"},
};

char *intToRoman(int num) {
  char *result =
      malloc(sizeof(*result) * 20); // ローマ数字の最大が15文字くらいらしい
  if (result == NULL)
    return NULL;
  *result = '\0';

  for (size_t i = 0; i < sizeof(roman_map) / sizeof(roman_map[0]); i++) {
    while (num >= roman_map[i].value) {
      strcat(result, roman_map[i].symbol);
      num -= roman_map[i].value;
    }
  }

  return (result);
}

int main(int ac, char **av) {
  (void)ac;

  printf("%s\n", intToRoman(atoi(av[1])));
  return 0;
}
