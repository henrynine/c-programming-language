#include <stdio.h>
#include <string.h>

int any(char s1[], char s2[]);

int main() {
  char s1[1000], s2[1000];
  printf("Enter the first string: ");
  scanf("%s", s1);
  printf("Enter the second string: ");
  scanf("%s", s2);
  printf("First index from any(): %d\n", any(s1, s2));
}

// any: returns the first location in s1 where any character from s2 occurs,
//      or -1 if s1 contains no characters from s2
int any(char s1[], char s2[]) {
  int i;

  for (i = 0; s1[i] != '\0'; i++) {
    if (strchr(s2, s1[i]) != NULL) { //s[i] is in s2
      return i;
    }
  }
  return -1;
}
