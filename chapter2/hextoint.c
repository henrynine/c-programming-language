#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

#define MAXLENGTH 1000

int htoi(char hex[]);

int main() {
  char input[MAXLENGTH];
  printf("Enter the number to convert: ");
  scanf("%s", input);
  printf("%s in hex is %d\n", input, htoi(input));
}

int htoi(char hex[]) {
  // remember to skip 0x or 0X at beginning
  // use isdigit and isalpha to see which conversion to use
  // subtract for alpha values, use islower to make easier
  char c;
  int int_value, i, as_int = 0;
  for (i = strlen(hex)-1 ; i >= 0; i--) {
    c = hex[i];
    if (c == 'x' || c == 'X')
      //encountered hex symbol
      break;
    if (isdigit(c)) {
      //is a digit
      int_value = c - '0';
    }
    else {
      // is a letter
      c = tolower(c);
      int_value = c - 'a' + 10;
    }
    as_int += int_value*pow(16, (strlen(hex)-1-i));
  }
  return as_int;
}
