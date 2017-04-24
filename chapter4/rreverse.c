#include <stdio.h>

void reverse(char [], int, int); // recursively reverses a string
void swap(char [], int, int); // swap two chars in a string

int main() {
  char r[] = "reverse this";

  printf("\"%s\" reversed is \"", r);
  reverse(r, 0, 11);

  printf("%s\"\n", r);
}

void reverse(char s[], int left, int right) {
  swap(s, left, right);
  if (left < right)
    reverse(s, left+1, right-1);
  else
    swap(s, left, right);
}

void swap(char s[], int l, int r) {
  char temp;

  temp = s[l];
  s[l] = s[r];
  s[r] = temp;
}
