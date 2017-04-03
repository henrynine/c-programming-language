#include <stdio.h>

// count lines in input
main()
{
  int c, nl, b, t;

  nl = 0;
  b = 0;
  t = 0;
  while ((c = getchar()) != EOF)
    if (c == '\n')
      ++nl;
    if (c == ' ')
      ++b;
    if (c == '\t')
      ++t;
  printf("%d lines\n", nl);
  printf("%d blanks\n", b);
  printf("%d tabs\n", t);

}
