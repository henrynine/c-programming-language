#include <stdio.h>

// design a more efficient bitcount algorithm

int orig_bitcount(unsigned x);
int fast_bitcount(unsigned x);

int main() {
  printf("orig_bitcount(0x1F) = %d\n", orig_bitcount(0x1F));
  printf("fast_bitcount(0x1F) = %d\n", fast_bitcount(0x1F));
  unsigned hex = 0xF6;
  //printf("1111 0110 &= (1111 0110 - 1) : %d\n", hex &= (hex - 1));
  /* 1111 0110 = 1111 0110
               & 1111 0101
     1000
     new = 1000 & 0111
     deletes the rightmost one bit because subtracting one from a number
     shifts the rightmost one to right by one digit and fills the zeros with
     ones, then & cancels out any complemented digits
     */
}

// bitcount: count the number of bits in x set to 1
int orig_bitcount(unsigned x) {
  int b;

  for (b = 0; x != 0; x >>= 1)
    if (x & 01)
      b++;
  return b;
}

// bitcount: count the number of bits in x set to 1
int fast_bitcount(unsigned x) {
  int b = 1;
  while ((x &= (x-1)) != 0)
    b++;
  return b;
}
