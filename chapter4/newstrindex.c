#include <stdio.h>
#define MAXLINE 1000

int get_line(char line[], int max);
int strindex(char s[], char t[]);
char pattern[] = "Line"; // pattern to search for

int main()
{
  char line1[MAXLINE] = "Line one";
  char line2[MAXLINE] = "space Line two";
  int found = 0; // count matching lines
  int linepos = 0; // store rightmost position in line that matches the pattern
  int i = 0;

  i++;
  if ((linepos = strindex(line1, pattern)) >= 0) {
    printf("Pattern found at index %d on line %d\n", linepos, i);
    found++;
  }
  i++;
  if ((linepos = strindex(line2, pattern)) >= 0) {
    printf("Pattern found at index %d on line %d\n", linepos, i);
    found++;
  }
 
  return found;
}

/* get_line: get line into s, return length */
int get_line(char s[], int lim)
{
  int c, i;

  i = 0;
  while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
    s[i++] = c;
  if (c=='\n')
    s[i++] = c;
  s[i] = '\0';
  return i;
}

/* strindex: returns the position of the rightmost occurence of t in s, or
             -1 if there is none */
int strindex(char s[], char t[])
{
  int i, j, k;
  int max_index = -1;

  for (i = 0; s[i] != '\0'; i++) {
    for (j=i, k=0; t[k]!='\0' && s[j]==t[k]; j++, k++)
      ;
    if (k > 0 && t[k] == '\0')
      max_index = i;
  }
  return max_index; 
}

