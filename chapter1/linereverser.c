#include <stdio.h>
#define MAXLINE 1000 // maximum line length

int get_line(char s[], int maxline);
void reverse(char s[], int len);

int main()
{
  // get line input and reverse it
  int len;
  char line[MAXLINE];

  while ((len = get_line(line, MAXLINE)) > 0) {
    reverse(line, len);
    printf("%s\n", line);
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

// len is length of s[]
// reverse: reverse a string
void reverse(char s[], int len)
{
  char front, back;

  int i;
  for (i = 0; i < len/2; ++i) {
    front = s[i];
    back = s[len-i-1];
    s[i] = back;
    s[len-i-1] = front;
  }
}
