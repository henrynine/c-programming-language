#include <stdio.h>
#define MAXLINE 1000

int get_line(char s[], int maxline);
void remove_trailing_whitespace(char line[], int lim);

int main()
{
  int len;
  char line[MAXLINE];

  while ((len = get_line(line, MAXLINE)) > 0) {
    remove_trailing_whitespace(line, MAXLINE);
    printf("%s", line);
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

// remove trailing whitespace, if the whole line is blank, remove it entirely
void remove_trailing_whitespace(char line[], int lim)
{
  // find the index of the last non-whitespace character
  int i, last_char_i = -1;
  for (i = 0; i < lim && line[i] != '\0'; ++i) {
    if (line[i] != '\n' && line[i] != ' ' && line[i] != '\t') {
      last_char_i = i;
    }
  }

  line[last_char_i+1] = '\0';
}
