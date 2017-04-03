#include <stdio.h>

// Replaces strings of blanks with tabs and blanks

#define TABWIDTH 8
#define MAXLINE 1000

void entab_line(char line[], int tab_width, int lim);
int get_line(char line[], int maxline);

int main()
{
  // get line input
  // call entab_line on it
  int len;
  char line[MAXLINE];

  while ((len = get_line(line, MAXLINE)) > 0) {
    entab_line(line, TABWIDTH, MAXLINE);
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

void entab_line(char line[], int tab_width, int lim)
{
  int cblanks = 0;

  int i;


  for (i = 0; i < lim && line[i] != '\0'; i++) {
    if (line[i] == ' ') {
      ++cblanks; // add to the consecutive blanks counter
    }
    else {
      // is not a blank
      if (cblanks > 0) { // ends a run of blanks
        // print the right number of tabs and blanks
        int chars_past_tabstop = i % TABWIDTH;
        int chars_before_last_tabstop = cblanks - chars_past_tabstop;
        int j;
        // print tabs to get to the last tabstop
        // print blanks equal to the chars past the tabstop
        for (j = 0; j < chars_before_last_tabstop; j+= TABWIDTH) {
          putchar('\t');
        }
        for (j = 0; j < chars_past_tabstop; j++) {
          putchar(' ');
        }
      }
      putchar(line[i]);
      cblanks = 0;
    }
  }

}
