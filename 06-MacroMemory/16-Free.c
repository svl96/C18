#include <stdio.h>
#include <stdlib.h>

// разберем более подробно этот пример. 
int main(void) {

  // выделсяется память размера int * 10.
  // 10 блоков с интом  
  int *x = calloc(10, sizeof(*x));

  // присваиватеся этим блокам какое-то значение 
  for (size_t i = 0; i != 10; ++i)
    x[i] = 10 - 1 - i;

  // теперь пытается выветси значения
  // в последнем элементе у нас лежит 0 
  int *p = x;
  while(*p) {
    // эквивалент
    // printf("%d\n", [x + 1])
    // при этом значение x больше не указывает на начало, то которое было
    // чтобы этого избежаь надо скопировать в новый поинтер
    printf("%d\n", *p++);
    printf("%p\n", (void *)p);
    printf("%p\n", (void *)x);
  }

  free(x);
}
