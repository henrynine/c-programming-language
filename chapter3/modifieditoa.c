#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include <stdlib.h>
#define MAXLENGTH 30

void new_itoa(int n, char s[]);
void old_itoa(int n, char s[]);
void padded_itoa(int n, char s[], int m);
char *strrev(char *str);

int main() {
  int test1 = 10;
  int test2 = -30;
  int test3 = INT_MIN;
  char s[MAXLENGTH];
  int i;

  // initialize s
  for (i = 0; i < MAXLENGTH; i++) {
    s[i] = '\0';
  }

  // test with values appropriate for old_itoa
  old_itoa(test1, s);
  printf("testing %d: %s\n", test1, s);

  // reinitialize s
  for (i = 0; i < MAXLENGTH; i++) {
    s[i] = '\0';
  }

  old_itoa(test2, s);
  printf("testing %d: %s\n", test1, s);

  // reinitialize s
  for (i = 0; i < MAXLENGTH; i++) {
    s[i] = '\0';
  }

  old_itoa(test3, s);
  printf("testing %d: %s\n", test3, s);

  // reinitialize s
  for (i = 0; i < MAXLENGTH; i++) {
    s[i] = '\0';
  }
  new_itoa(test3, s);
  printf("new testing %d: %s\n", test3, s);

  // reinitialize s
  for (i = 0; i < MAXLENGTH; i++) {
    s[i] = '\0';
  }
  padded_itoa(test2, s, 15);
  printf("padded %d: %s\n", test2, s);
}


/* itoa:  convert n to characters in s
   with old_itoa, abs(INT_MIN) > INT_MAX by one
*/
void new_itoa(int n, char s[])
{
  int i;
  char last_digit;
  if (n == INT_MIN) {
    last_digit = abs(n%10)+'0';
    n /= 10;
    old_itoa(n, s);
    // traverse to_mod until reaching the end then add the last digit
    for (i = 0; i+1 < MAXLENGTH; i++) {
      if (s[i] == '\0') {
        s[i] = last_digit;
        s[i+1] = '\0';
        break;
      }
    }
  }
  else {
    return old_itoa(n, s);
  }
}

/* itoa:  convert n to characters in s */
void old_itoa(int n, char s[])
{
  int i, sign;
    if ((sign = n) < 0)  /* record sign */
      n = -n;          /* make n positive */
    i = 0;
    do {      /* generate digits in reverse order */
      s[i++]=n%10+'0'; /*getnextdigit*/
    } while ((n /= 10) > 0);
    if (sign < 0)
      s[i++] = '-';
    s[i] = '\0';
    strrev(s);
}

/* padded_itoa: like itoa, but m is the minimum field width: the converted
                number will be padded with blanks on the left if needed */
void padded_itoa(int n, char s[], int m)
{
  int i;
  new_itoa(n, s);
  if ((i = strlen(s)) < m) {
    // string is too short
    strrev(s);
    for (i; i < m; i++)
      s[i] = ' ';
    s[i] = '\0';
    strrev(s);
  }
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
