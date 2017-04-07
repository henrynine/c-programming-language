#include <stdio.h>
#include <ctype.h>
#define MAXLENGTH 10000

void expand(char s1[], char s2[]);

int main() {
  char test[] = "hi there: a-b-c a-z0-9 -a-z-";
  char new[MAXLENGTH];
  int i;

  // initialize new
  for (i = 0; i < MAXLENGTH; i++) {
    new[i] = '\0';
  }

  // test
  printf("original: %s\n", test);
  expand(test, new);
  printf("after expand(): %s\n", new);
}

/* expand: expands shorthand notations like a-z in string s1 into the
           equivalent complete list abc...xyz in s2.
*/
void expand(char s1[], char s2[]) {
  char c;
  int i; // index in s1
  int j; // index in s2
  int k; // transcription index
  for (i = j = 0; (c = s1[i]) != '\0' && j < MAXLENGTH; i++) {
    if (c == '-' && isalnum(s1[i-1]) && isalnum(s1[i+1])) {
      // expand
      if (isalpha(s1[i-1]) == isalpha(s1[i+1])) { // share dig/alpha status
        for (k = s1[i-1]; k <= s1[i+1]; k++)
          s2[j++] = k;
      }
      i++; // skip over next character, dash is skipped by not printing
      // still double prints first character shit need to change order
    }
    else
      s2[j++] = c; // no expansion
  }
}
