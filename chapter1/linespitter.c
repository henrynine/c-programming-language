#include <stdio.h>

#define IN  1  // in a word
#define OUT 1  // out of a word

// prints the input back, one word per line

int main()
{
  int c, state;

  state = OUT;

  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\t' || c == '\n') {
      if (state == IN) {
        putchar('\n');
        state = OUT;
      }
    }
    else if (state == OUT){
      state = IN;
      putchar(c);
    }
  }
}
