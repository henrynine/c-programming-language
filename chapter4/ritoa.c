#include <stdio.h>

/* this is a recursive version of itoa (convert integer to string) */

#define MAXLENGTH 100

void itoa(int, char []);
char s[MAXLENGTH];
int start_loc;

int main() {
  int i = 12043;

  start_loc = 0;
  itoa(i, s);

  printf("In string form, 12043 is: %s\n", s);
}

/* itoa: recursively convert an integer into a string
         doesn't work with largest negative number */
void itoa(int i, char s[]) {
  if (i < 0) {
    s[start_loc++] = '-';
    i = -i;
  }
  if (i / 10)
    itoa((i / 10), s);
  s[start_loc++] = (i % 10 + '0');
}
