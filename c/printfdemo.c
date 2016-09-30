/* Hernan Palombo */
/* printf example */

#include <stdio.h>

void main (void) {

  /* We will use one floating-point and one integer variable. */

  double x = .00000123456789;
  int n = 12345;


  /* Display plain text. */

  printf("This is a test\n");
  printf("This\tis\nanother\ttest\n\n");


  /* Display an integer. */

  printf("Here is n: %d\n\n", n);
  

  /* Display a double three different ways. */

  printf("Here is x: %g\n", x);
  printf("Here is x: %f\n", x);
  printf("Here is x: %e\n\n", x);


  /* Display two numbers. */

  printf("Here are n (%d) and x (%g)\n", n, x);

}
