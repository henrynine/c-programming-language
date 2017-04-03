#include <stdio.h>

// removes comments from a c program
/* two types of comments:
  //......\n
  slash*.......star/ */
#define MAXLINE 1000
#define TRUE 1
#define FALSE 0
#define ONELINE 1
#define MULTILINE 0
#define NONE -1

int get_line(char line[], int maxline);
void decomment(char line[], int lim);
void reset_comment(void);
void enter_comment(int ctype);
int in_comment = FALSE;
int comment_type;


int main()
{
  // get line input
  // call decomment on it
  int len;
  char line[MAXLINE];

  while ((len = get_line(line, MAXLINE)) > 0) {
    decomment(line, MAXLINE);
  }
}

void decomment(char line[], int lim) {
  // if in comment: look behind for end of comment
  // if out of comment: look ahead for beginning of comment
  int i;

  for (i = 0; i < lim && line[i] != '\0'; i++) {
    if (in_comment == TRUE) {
      if (comment_type == ONELINE && line[i] == '\n') {
        // reset comment memory for next line
        reset_comment();
        putchar('\n');
      }
      else if (comment_type == MULTILINE) {
        if (line[i] == '/' && line[i-1] == '*') {
          // comment is over
          reset_comment();
        }
      }
    }
    else {
      if (line[i] == '/' && line[i+1] == '/') {
        enter_comment(ONELINE);
      }
      else if (line[i] == '/' && line[i+1] == '*') {
        enter_comment(MULTILINE);
      }
      else {
        putchar(line[i]);
      }
    }
  }
}

void reset_comment(void) {
  in_comment = FALSE;
  comment_type = NONE;
}

void enter_comment(int ctype) {
  in_comment = TRUE;
  comment_type = ctype;
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
