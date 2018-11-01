#include "08-IncludeGuards.h"
#include "08-IncludeGuards.h"

int main(void) {
  return sizeof(struct T);
}
// пример макроса, чтобы не использовать #pragma once 
/**

08-includeGuards.h

#ifndef _INCLUDE_GUARD_ 
#define _INCLUDE_GUARD_

// some code here 

#endif

**/ 
