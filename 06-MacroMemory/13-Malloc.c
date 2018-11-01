#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#define int_block(size) (size * sizeof(int))

#define CHECK_OR_GOTO(label, val) \
  if (!(val)) goto label
        
void init_line(int* h, unsigned line, int len, ...) {
  int *xs = h; 
  va_list args;
  va_start(args, len);

  for (unsigned i = 0; i != len; ++i) {
    xs[i + line] = va_arg(args, int);
  }
  va_end(args);
}

int main(void) {

  // malloc -- аллоцируется память, 
  //
  // int *x = malloc(sizeof(x));
  // выделяем размер int
  int *x = malloc(sizeof(int));
  *x = 0;

  int *xs = malloc(int_block(10000000000000000ULL)); // выделит 10 байтов
  CHECK_OR_GOTO(release, xs);
  // xs[10] на обращается к 10-му байту я так понял
  xs[0] = 10;
  xs[1] = 10;
  init_line(xs, 0, 10, 1,2,3,4,5,6,7,8,9,0); 
  // тут инты, поэтму будет запрашивать 
  // бОльший объем памяти.
  printf("%p %ld\n", (void*)x, sizeof(x));
  printf("%p %ld\n", (void*)x, sizeof(xs));

//  printf("%p %d\n", (void*)x, *x);
//  printf("%p %d\n", (void*)xs, xs[3]);
//  printf("%p %d\n", (void*)xs, xs[5]);
  printf("%s\n", "before release");
  release:
  printf("%s\n", "release");
  free(xs);
  free(x);
  // освобождение аллоцированной памяти 
  // никакой статической памяти
}
// malloc может вернуть 0, если не удалось найти память.
