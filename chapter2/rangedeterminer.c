#include <stdio.h>
#include <limits.h>

int main() {
  printf("unsigned char range: ");
  printf("0 to %d\n", UCHAR_MAX);
  printf("unsigned short range: ");
  printf("0 to %d\n", USHRT_MAX);
  printf("unsigned int range: ");
  printf("0 to %u\n", UINT_MAX);
  printf("unsigned long range: ");
  printf("0 to %lu\n", ULONG_MAX);
  printf("signed char range: ");
  printf("%d to %d\n", CHAR_MIN, CHAR_MAX);
  printf("signed short range: ");
  printf("%d to %d\n", SHRT_MIN, SHRT_MAX);
  printf("signed int range: ");
  printf("%d to %d\n", INT_MIN, INT_MAX);
  printf("signed long range: ");
  printf("%lu to %lu\n", LONG_MIN, LONG_MAX);
}
