#include <stdio.h>

// тут определсяеться макрос, которому передается 
// некоторое выажение, которому передается памаремтры
// возращается тройка цветов, как-то измененная
#define FOR_EACH_COLOR(expr) \
    expr(RED) expr(GREEN) expr(BLUE)

// тут определсяется макрос, который по значению возвращается запись с запятой
#define value(color) color,

// тут мы вызываем макрос, чтобы создать enum. перечисление всех цветов.
enum Color { FOR_EACH_COLOR(value) };

#undef value
// undef значит, что видимость value заканчивается

void print_color(int color) {
  switch (color) {
  	// определяем новый макрос принт, который создает case для определенного цвета, который ему передали. 
  	// этот кейс печатает цвет
#define print(color) \
  case color: printf(#color "\n"); break;
// тут создаем кейс для кажого цвета. 
    FOR_EACH_COLOR(print)
#undef print 
  }
}

int main(void) {
  print_color(RED);
  print_color(GREEN);
}
