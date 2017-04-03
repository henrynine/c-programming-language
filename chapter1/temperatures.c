#include <stdio.h>

/* print Farhenheit-Celsius table
    for fahr = 0, 20, ..., 300 */

int ftoc(int f);

int main()
{
  printf("== Temperature Conversion Chart ==\n");
  printf("%3s\t%6s\n", "F", "C");
  float fahr, celsius;
  float lower, upper, step;

  lower = 0; // lower limit of temperature scale
  upper = 300; // upper limit
  step = 20; // step size

  fahr = lower;
  while (fahr <= upper) {
    celsius = ftoc(fahr);
    printf("%3.0f\t%6.1f\n", fahr, celsius);
    fahr = fahr + step;
  }

  return 0;
}

int ftoc(int f)
{
  return (5.0/9.0) * (f-32.0);
}
