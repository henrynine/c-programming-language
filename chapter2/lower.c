#include <stdio.h>
#include <ctype.h>

void lower(char s[]);

int main() {
  char hi[] = "Hi ThErE";
  lower(hi);
  printf("lower(\"Hi ThErE\") = %s\n", hi);
}

void lower(char s[]) {
  int i;

  for (i = 0; s[i] != '\0'; i++) {
    s[i] = (isupper(s[i])) ? s[i] + 32 : s[i];
  }
}
