#include <stdio.h>

int getint(void); /*It prompts user to enter an integer, which it returns*/



/* Main program */
int main (void) {
  int x;

  x = getint();
  printf("The number entered is %d\n", x);
}

int getint(void) {
  int a;

  printf("Please enter an integer > ");
  scanf("%d", &a);
  return(a);
}

