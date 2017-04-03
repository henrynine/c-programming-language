#include <stdio.h>
#define MAXLINE 1000

int get_line(char line[], int maxline);


int main()
{
  int len;
  char line[MAXLINE];

  while ((len = get_line(line, MAXLINE)) > 0) {
    if (len > 80) {
      printf(line);
    }
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
