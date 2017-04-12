/* ADD:
       * list of commands
       */
#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <ctype.h>

#define MAXOP 100 // max size of operand or operator
#define NUMBER '0' // signal that a number was found
#define MAXVAL 100 // maximum depth of val stack
#define BUFSIZE 100 // maximum size of buffer

char buf[BUFSIZE]; // buffer for ungetch
int bufp = 0; // next free position in buf
int sp = 0; // next free stack position
double val[MAXVAL]; // stack
int getch(void); // buffered character retrieval
void ungetch(int); // buffered character 
int getop(char []); // get op to handle
void push(double); // push onto val stack
double pop(void); // pop from val stack
void printstack(void); // print the whole stack
void dupstack(void); // duplicate the stack
void clearstack(void); // clear the stack

/* reverse Polish calculator */
int main() 
{
  int type;
  double op2;
  char s[MAXOP];

  // printf("Type h to receive a list of commands\n");
  while ((type = getop(s)) != EOF) {
    double i, top, next;
    switch (type) {
    case NUMBER:
      push(atof(s));
      break;
    case '+':
      push(pop() + pop());
      break;
    case '*':
      push(pop() * pop());
      break;
    case '-':
      op2 = pop(); // order matters
      push(pop() - op2);
      break;
    case '/':
      op2 = pop();
      if (op2 != 0.0)
        push(pop() / op2);
      else
        printf("error: zero divisor\n");
      break;
    case '%':
      op2 = pop();
      if (op2 != 0.0)
        push(((int)pop()) % ((int)(op2)));
      else
        printf("error: zero divisor\n");
      break;
    case 'p': // print the stack
      printstack(); 
      break;
    case 'd': // duplicate the stack 
      dupstack();
      break;
    case 's': // swap the top two stack elements
      top = pop();
      next = pop();
      push(top);
      push(next);
      break;
    case 'c': // clear the stack
      clearstack();
      break;
    case '\n':
      printf("\t%.8g\n", pop());
      break;
    default:
      printf("error: unknown command %s\n", s);
      break;
    }
  }
  return 0;
}

/* push: push f onto value stack */
void push(double f)
{
  if (sp < MAXVAL)
    val[sp++] = f;
  else
    printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void)
{
  if (sp > 0)
    return val[--sp];
  else {
    printf("error: stack empty\n");
    return 0.0;
  }
}

// print the whole stack
void printstack(void)
{
  int i;
  printf("stack: ");
  for (i = 0; i < sp; i++) {
    printf("%.2f ", val[i]); 
  }
  printf("\n");
}

// duplicate the stack
void dupstack(void) {
  int i, og_sp = sp;
  for (i = 0; i < og_sp; i++)
    push(val[i]);
}

// clear the stack
void clearstack(void) {
  int i;
  for (i = 0; i < MAXVAL; i++) {
    val[i] = 0.0;
  }
  sp = 0;
}
#include <ctype.h>

int getch(void);
void ungetch(int);

/* getop: get next character or numeric operand */
int getop(char s[])
{
  int i, c, d;

  while((s[0] = c = getch()) == ' ' || c == '\t')
    ;
  s[1] = '\0';
  if (c == '-' && isdigit(d = getch()))
    ungetch(d);
  else if (!isdigit(c) && c != '.')
    return c; // not a number
  i = 0;
  if (isdigit(c) || c == '-') // collect integer part
    while (isdigit(s[++i] = c = getch()))
      ;
  if (c == '.') // collect fraction part
    while (isdigit(s[++i] = c = getch()))
      ;
  s[i] = '\0';
  if (c != EOF)
    ungetch(c);
  return NUMBER;
}

int getch(void) // get a (possibly pushed-back) character 
{
  return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) // push character back on input
{
  if (bufp >= BUFSIZE)
    printf("ungetch: too many characters\n");
  else
    buf[bufp++] = c;
}
