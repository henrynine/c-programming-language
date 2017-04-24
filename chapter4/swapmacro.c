#include <stdio.h>

#define swap(t,x,y) t x ## y; x ## y = x; x = y; y = x ## y;

int main() {
  int x = 5;
  int y = 10;
  printf("x, y: %d, %d\n", x, y);
  swap(int, x, y);
  printf("swapped: x, y: %d, %d\n", x, y);

  char a = 'a';
  char b = 'b';

  printf("a, b: %c, %c\n", a, b);
  swap(char, a, b);
  printf("swapped: a, b: %c, %c\n", a, b);
}
