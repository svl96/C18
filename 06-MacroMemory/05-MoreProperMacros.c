#include <stdio.h>

// тут просто определяется enum
enum LOG_LEVEL {
  ERROR, WARNING, INFO, DEBUG
};

// далее определяется макрос, который будет вставлять код 
// если подходящий level то выводим сообщение и log level
#define LOG(level, msg) \
  if (level <= CURRENT_LOG_LEVEL) \
    fprintf(stderr, "%s: " msg "\n", #level)

// тут определятся макрос с некотроыми аргуметами. которые можно передать 
// и эти аргумета находятся в __VA_ARGS__
// напечатать сообщение с некоторыми аргуметами.
#define PLOG(level, msg, ...) \
  if (level <= CURRENT_LOG_LEVEL) \
    fprintf(stderr, "%s: " msg "\n", #level, __VA_ARGS__)

#define CURRENT_LOG_LEVEL WARNING

int main(void) {
  LOG(INFO, "some shit happened");
  LOG(ERROR, "some bad shit happened!");

  int x = 10;
  PLOG(ERROR, "some bad shit happened: x == %d!", x);
}
