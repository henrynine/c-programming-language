#include <stdio.h>
#define MAXLENGTH 10000

void escape(char s[], char t[]);
void unescape(char s[], char t[]);

int main() {
  char test[] = "test\tnice\noh yeah";
  char transfer_to[MAXLENGTH];
  int i;

  // initialize transfer_to
  for (i = 0; i < MAXLENGTH; i++)
    transfer_to[i] = '\0';


  printf("original: %s\n", test);
  escape(transfer_to, test);
  printf("after escape(): %s\n", transfer_to);

  printf("---------\n");

  char test2[] = "test\\tnice\\nohyeah";
  // initialize transfer_to
  for (i = 0; i < MAXLENGTH; i++)
    transfer_to[i] = '\0';

  printf("original: %s\n", test2);
  unescape(transfer_to, test2);
  printf("after unescape(): %s\n", transfer_to);
}

/* escape: turns newline and tab characters into visible escape sequences
           as it copies string t to string s */
void escape(char s[], char t[]) {
  char c;
  int i; // index of current location in old string
  int j; // index of current location in new string
  for (int i = j = 0; (c=t[i]) > 0 && i < MAXLENGTH && j < MAXLENGTH; i++) {
    switch(c) {
      case '\n':
        s[j++] = '\\';
        s[j++] = 'n';
        break;
      case '\t':
        s[j++] = '\\';
        s[j++] = 't';
        break;
      default:
        s[j++] = t[i];
        break;
    }
  }
}

/* unescape: turns newline and tab escape sequences into the right characters
             as it copies string t to string s */
void unescape(char s[], char t[]) {
  char c;
  int i; // index of current location in old string
  int j; // index of current location in new string
  for (int i = j = 0; (c=t[i]) > 0 && i < MAXLENGTH && j < MAXLENGTH; i++) {
    switch(c) {
      case '\\':
        switch(t[i+1]) {
          case 'n':
            s[j++] = '\n';
            i++;
            break;
          case 't':
            s[j++] = '\n';
            i++;
            break;
          default:
            s[j++] = t[i];
            break;
        }
        break;
      default:
        s[j++] = t[i];
        break;
    }
  }
}
