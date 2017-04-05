#include <stdio.h>

// has three bitwise operations: setbits, invert, and rightrot

unsigned getbits(unsigned x, int p, int n);
unsigned setbits(unsigned x, int p, int n, unsigned y);
unsigned invert(unsigned x, int p, int n);
unsigned rightort(unsigned x, int n);


int main() {
  // call set on two compile-time constants
  printf("setbits(0101 0101, 5, 3, 0011 0011) = %u\n", setbits(0x55, 5, 3, 0x33));
  // should be 93
  printf("setbits(0101 0101, 2, 3, 0011 0011) = %u\n", setbits(0x55, 2, 3, 0x33));
  // should be 83
  printf("invert(1111 0000, 5, 4) = %u\n", invert(0xF0, 5, 4));
  // should be 204
  //printf("rightrot(1100 1010, 2) = %u\n", invert(0xCB));
}

/* getbits:  get n bits from position p */
unsigned getbits(unsigned x, int p, int n)
{
   return (x >> (p+1-n)) & ~(~0 << n);
}


/* setbits: returns x with the n bits that begin at position p set to the
            rightmost n bits of y, leaving the other bits unchanged */
unsigned setbits(unsigned x, int p, int n, unsigned y) {
  // use different variables for the left, middle, and right
  unsigned left_chunk, middle_chunk, right_chunk;
  /* wipe everything right of theleft chunk and bring it back to make room for
     the middle chunk */
  left_chunk = x >> (p + 1) << n;
  // the middle chunk is the rightmost part of y
  middle_chunk = getbits(y, (n-1), n);
  // the right chunk is the part of the original x after the substitution
  right_chunk = getbits(x, (p-n), (p-n+1));
  /* combine the left and middle chunks, then shift over and combine
     with the right chunk */
  return ((left_chunk | middle_chunk) << (p-n+1) | right_chunk);
}

/* invert: returns x with the n bits that begin at position p inverted,
           leaving the others unchanged */
unsigned invert(unsigned x, int p, int n) {
  // trim into left, middle, and right, then complement the right
  unsigned left_chunk, middle_chunk, right_chunk;
  /* wipe everything right of the left chunk and bring it back to make room
     for the middle chunk */
  left_chunk = x >> (p+1) << n;
  // the middle chunk is the part in the middle to be complemented
  middle_chunk = getbits(x, p, n);
  // the right chunk is the rightmost part of x after the length of n from p
  right_chunk = getbits(x, (p-n), (p-n+1));

  //printf("l:%u m:%u r:%u \n", left_chunk, middle_chunk, right_chunk);
  // for the sample in main, should be: l: 48, m: 12, r: 0
  // working so far

  // add the complement (inverse) of the middle chunk
  left_chunk |= getbits(~middle_chunk, (n-1), n);

  // shift the left chunk back to its original position
  left_chunk <<= (p+1-n);
  // add back the right chunk
  left_chunk |= right_chunk;
  return left_chunk;
}

/* rightrot: returns the value of integer x rotated to the right by n
             positions /
unsigned rightrot(int x, int n) {
  unsigned as_bin;
  as_bin = (unsigned) x;
  printf("%u", as_bin);
}*/
