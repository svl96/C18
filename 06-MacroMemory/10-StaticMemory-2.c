#include <stdio.h>

#define SIZE 100500

// статическая память
char message[SIZE];

int main(void) {
  // память выделенная на стеке, насколько я понял
  char message2[] = "Hello, world!";
  char message3[SIZE];
  //char message4* = "Hello, world!";
  // строковые литералы попадают в статическую read only область памяти 
  // эти области памяти read only - ее перезаписывать нельзя. 
  // есть области глабальные изменяемые, есть неизменяемые.
   
  printf("%p %p %p\n",
         (void *)message,
         (void *)message2,
         (void *)message3);

  return 0;
}
// на стеке, тоже ограниченное количество памяти, 
// думаем о том, как храним. 