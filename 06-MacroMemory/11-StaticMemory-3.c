#include <stdio.h>

int count(int x) {

  static int y;
  return y += x;
}

int main(void) {
  printf("%d\n", count(1));
  printf("%d\n", count(2));
  printf("%d\n", count(3));
}


// static - вляет на область видимости
// этот static говорит, что переменная будет храниться 
// в статической области видимости

// будет заводиться не когда вызывается
// статическая область памяти гарантируется инициализируется. 
