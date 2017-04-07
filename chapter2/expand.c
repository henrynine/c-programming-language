#include <stdio.h>
#include <ctype.h>
#define MAXLENGTH 10000

void expand(char s1[], char s2[]);
int is_expansion(char one, char two, char three);

int main() {
  char test[] = "hi there: a-b-c-d a-z0-9 -a-z- a-";
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
           equivalent complete list abc...xyz in s2. */
void expand(char s1[], char s2[]) {
  char c;
  int i; // index in s1
  int j; // index in s2
  int k; // transcription index
  for (i = j = 0; s1[i] != '\0' && j < MAXLENGTH; i++) {
    if (is_expansion(s1[i], s1[i+1], s1[i+2])) {
      // expand
      if (isalpha(s1[i]) == isalpha(s1[i+2])) { // share dig/alpha status
        for (k = s1[i]; k <= s1[i+2]; k++)
          s2[j++] = k;
      }
      /* only advance beyond the end of the expansion if the final character
         does not begin a new expansion */
      if (is_expansion(s1[i+2], s1[i+3], s1[i+4]))
        i++;
      else
        i+=2;
    }
    else
      s2[j++] = s1[i]; // no expansion
  }
}

/* is_expansion: checks if a three character sequence forms an expansion */
int is_expansion(char a, char b, char c) {
  return ((isalpha(a) && isalpha(c)) || (isdigit(a) && isdigit(c))) && b == '-';
}
