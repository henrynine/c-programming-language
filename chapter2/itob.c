#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAXLENGTH 100

void itob(int n, char s[], int b);
char base_char(int n);
char *strrev(char *str);

int main() {
  int test1 = 0x1F5E;
  int test2 = 23450989;
  char s[MAXLENGTH];
  int i;

  // initialize s
  for (i = 0; i < MAXLENGTH; i++) {
    s[i] = '\0';
  }

  itob(test1, s, 16);
  printf("test1: %d in hex is: ", test1);
  printf("%s\n", s);
}

/* itob: converts integer n into a base b representation in the string s. */
void itob(int n, char s[], int b) {
  int sign, i = 0;
  if ((sign = n) < 0)  // record sign
    n = -n;            // make n positive
  do {
    s[i++] = base_char(n%b);
  } while ((n /= b) > 0);
  if (sign < 0)
    s[i++] = '-';
  s[i] = '\0';
  strrev(s);
}

/* base_char: returns the base representation of an int from 0-F, assumes
              n is positive */
char base_char(int n) {
  if (n < 10)
    return n+'0';
  else {
    switch(n) {
      case 10:
        return 'A';
      case 11:
        return 'B';
      case 12:
        return 'C';
      case 13:
        return 'D';
      case 14:
        return 'E';
      case 15:
        return 'F';
      default:
        return '?';
    }
  }
  return '?';
}

/*
**  STRREV.C - reverse a string in place
**
**  public domain by Bob Stout
*/

char *strrev(char *str)
{
      char *p1, *p2;

      if (! str || ! *str)
            return str;
      for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
      {
            *p1 ^= *p2;
            *p2 ^= *p1;
            *p1 ^= *p2;
      }
      return str;
}
