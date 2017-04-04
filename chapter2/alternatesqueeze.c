#include <stdio.h>
#include <string.h>

void squeeze(char s1[], char s2[]);

int main() {
  char s1[1000], s2[1000];
  printf("Enter the first string: ");
  scanf("%s", s1);
  printf("Enter the second string: ");
  scanf("%s", s2);
  squeeze(s1, s2);
  printf("Squeezed: %s\n", s1);
}

// void squeeze: delete all chars in s2 from s1
void squeeze(char s[], char s2[]) {
  int i, j;

  for (i = j = 0; s[i] != '\0'; i++) {
    if (strchr(s2, s[i]) == NULL) { // s[i] isn't in s2
      s[j++] = s[i];
    }
  }
  s[j] = '\0';
}
