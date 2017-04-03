#include <stdio.h>

// call out unmatched parentheses, brackets, braces, and quotes

/* similar to removing commnents: just add to open and closed count for each
   symbol
   could add line and char of offending symbol, but not rn */

#define PARENS 0
#define BRACKETS 1
#define BRACES 2
#define SQUOTES 3 // doesn't fw apostrophes
#define DQUOTES 4
#define CSPECS 5
#define MAXLINE 1000

int get_line(char line[], int maxline);
void scan_for_special_chars(char line[], int maxline);
void tally_errors(void);

int special_chars_counts[CSPECS];


int main() {
  int len, i;
  char line[MAXLINE];
  // initalize special_chars_counts
  for (i = 0; i < CSPECS; i++) {
    special_chars_counts[i] = 0;
  }
  printf("scc:\n");
  for (int i = 0; i < 5; i++) {
    printf("%d: %d\n", i, special_chars_counts[i]);
  }

  while ((len = get_line(line, MAXLINE)) > 0) {
    scan_for_special_chars(line, MAXLINE);
  }

  tally_errors();

}

// scan a line for special chars
void scan_for_special_chars(char line[], int maxline) {
  for (int i = 0; line[i] != '\0' && i < maxline; i++) {
    switch(line[i]) {
      case '(':
        ++special_chars_counts[PARENS];
        break;
      case ')':
        --special_chars_counts[PARENS];
        break;
      case '[':
        ++special_chars_counts[BRACKETS];
        break;
      case ']':
        --special_chars_counts[BRACKETS];
        break;
      case '{':
        ++special_chars_counts[BRACES];
        break;
      case '}':
        --special_chars_counts[BRACES];
        break;
      case '\'': // divis by 2
        ++special_chars_counts[SQUOTES];
        break;
      case '\"': // divis by 2
        ++special_chars_counts[DQUOTES];
        break;
      default:
        ; // do nothing
    }
  }
}

void tally_errors() {
  //parens
  //brackets
  //braces
  printf("scc:\n");
  for (int i = 0; i < 5; i++) {
    printf("%d: %d\n", i, special_chars_counts[i]);
  }
  for (int i = 0; i < 3; i++) {
    if (special_chars_counts[i] != 0) {
      printf("You have an unmatched parenthesis, bracket, or brace.\n");
      break;
    }
  }
  for (int i = 3; i < 5; i++) {
    if ((special_chars_counts[i] % 2) != 0) {
      printf("You have an unmatched single or double quote\n");
      break;
    }
  }
  //squotes
  //dquotes
}

// get_line: read a line into s, return length
int get_line(char s[], int lim)
{
  int c, i;

  for (i = 0; i < lim-1 && (c=getchar()) != EOF && c!='\n'; ++i)
    s[i] = c;
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}
