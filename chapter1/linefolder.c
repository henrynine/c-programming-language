#include <stdio.h>

/* folds long input lines after the last non-blank character that occurs before
   the n-th column of input */
// doesn't actually quite fit the program but fuck it
// how to fix: after a blank, store the chars etc.
// come back to later
#define MAXLINE 1000
#define FOLDLIMIT 40
#define TRUE 1
#define FALSE 0

int get_line(char s[], int maxline);
void fold_line(char s[], int lim, int fold_limit);

int main()
{
  // get line input
  // call fold_line on it
  int len;
  char line[MAXLINE];

  while ((len = get_line(line, MAXLINE)) > 0) {
    fold_line(line, MAXLINE, FOLDLIMIT);
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

void nullify_string(char s[], int lim) {
  int i;
  for (i = 0; i < lim; i++) {
    s[i] = '\0';
  }
}

void fold_line(char s[], int lim, int fold_limit) {
  // store chars since last blank
  // upon encountering a blank, print until that blank
  // store cblanks too
  char current, since_last_blank[lim];
  int i, j, cblanks = 0, chars_since_blank = 0, chars_on_line = 0;
  int blank_on_line;

  // initalize since_last_blank
  nullify_string(since_last_blank, MAXLINE);

  for (i = 0; i < lim && s[i] != '\0'; i++) {
    if ((current = s[i]) != ' ') { // if not blank
      ++chars_on_line;
      if (chars_on_line > fold_limit) {
        // hyphenate and start a new line
      }
      else {
        // print blanks, if any
        if (cblanks > 0) {
          for (j = 0; j < cblanks; j++) {
            putchar(' ');
          }
        }
        // add to the string of what to print if it fits
        since_last_blank[chars_since_blank] = current;
        ++chars_since_blank;
      }
      cblanks = 0;
    }
    else { // is blank
      // if there is stuff waiting to be printed, print it and nullify cslb
      if (chars_since_blank > 0) {
        // print queued chars
        for (j = 0; j < lim && since_last_blank[j] != '\0'; j++) {
          putchar(since_last_blank[j]);
        }
        nullify_string(since_last_blank, MAXLINE);
        chars_since_blank = 0;
      }
      ++chars_on_line;
      ++cblanks;
      if (chars_on_line > fold_limit) {
        putchar('\n');
        blank_on_line = FALSE;
      }
    }
  }



}

void bad_hypenate_line(char s[], int lim, int fold_limit)
{
  int i;
  char current;
  int j, cblanks, chars_on_line = 0;

  for (i = 0; i < lim && s[i] != '\0'; i++) {
    // if it's a nonblank char, print it
    // if it's blank, count up the blanks
    /* upon re-entering non-blank territory, if it's before the fold,
       print the blanks counted up
       if after the fold, disregard all those blanks and begin printing on
       a new line
       if the fold is reached with no blanks, print a hyphen then resume on
       a new line */
    if ((current = s[i]) != ' ') { // isn't blank
      if (cblanks > 0) {
        if (chars_on_line > fold_limit) {
          // blanks end the line, start a new one without printing the blanks
          cblanks = chars_on_line = 0;
          putchar('\n');
        }
        else {
          // the line isn't over yet, print out the blanks
          for (j = 0; j < cblanks; j++) {
            putchar(' ');
          }
          cblanks = 0;
        }
      }
      else if (chars_on_line > fold_limit) {
        // hyphenate
        cblanks = chars_on_line = 0;
        putchar('-');
        putchar('\n');
      }
      putchar(current);
      ++chars_on_line;
    }
    else { // is blank
      ++cblanks;
      ++chars_on_line;
    }
  }
}
