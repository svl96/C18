#include <stdio.h>
#include <stdlib.h>

void print(int *x) {
  int *p = x;
  for (; *p; ++p)
    printf("%d ", *p);
  printf("\n");
  // мы не должны освобождать память которую нам передали
  // free(x);
  // освобождает память под x
  // В Си - мы не можем
}

int main(void) {
  int *x = malloc(5 * sizeof(*x));
  x[0] = 10;
  x[4 * sizeof(*x)] = 0;
  print(x);

  int *y = x;
  y[0] = 20;
  y[4 * sizeof(*x)] = 0;
  print(y);
  free(x);
}

// х - чистится 2 раза
// надо чтобы четко было видно где выделяется, где освобождается. 
