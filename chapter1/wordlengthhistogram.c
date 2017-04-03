#include <stdio.h>

#define MAXWORDLENGTH 50 // maximum expected word length


// print a histogram of the length of words in the input

int main()
{
  /* make an array to count the number of words with
     length equal to the index in the array,
    assuming no words longer than 49 chars */
  int c, length_counts[MAXWORDLENGTH];
  int this_word_length = 0;

  // initialize the array
  for (int i = 0; i < MAXWORDLENGTH; i++)
    length_counts[i] = 0;

  while ((c = getchar()) != EOF) {
    // if the char isn't whitespace
    if (!(c == ' ' || c == '\t' || c == '\n')) {
      // add to the wordlength
      ++this_word_length;
    }
    // if it is whitespace
    else {
      // update the array
      ++length_counts[this_word_length];
      this_word_length = 0;
    }
  }

  // for now, just print the array
  printf("raw data:\n");
  for (int i = 0; i < MAXWORDLENGTH; ++i) {
    if (length_counts[i] != 0)
      printf("length: %d  count: %d\n", i, length_counts[i]);
  }

  // print the histogram
  printf("\nhistogram:\n");
  for (int i = 0; i < MAXWORDLENGTH; ++i) {
    printf("%3d:", i);
    for (int j = 0; j < length_counts[i]; j++)
      printf("X");
    printf("\n");
  }


}
