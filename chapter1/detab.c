#include <stdio.h>

/* replaces tabs in the input with the proper number of blanks to space to the
   next tab stop */

#define TABSTOP 8 // width between tabstops
#define MAXLINE 1000 // maximum line length

void detab_line(char line[], int tab_width, int lim);
int get_line(char line[], int maxline);

int main()
{
  // get line input
  // call detab_line on it
  int len;
  char line[MAXLINE];

  while ((len = get_line(line, MAXLINE)) > 0) {
    detab_line(line, TABSTOP, MAXLINE);
  }
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

void detab_line(char line[], int tab_width, int lim)
{
  int i, j;
  // traverse the line
  for (i = 0; i < lim && line[i] != '\0'; i++) {
    if (line[i] != '\t') {
      putchar(line[i]);
    }
    else { // char is a tab
      // print spaces until the next tabstop
      for (j = 0; j < TABSTOP - (i % TABSTOP); j++) {
        putchar(' ');
      }
    }
  }
}
