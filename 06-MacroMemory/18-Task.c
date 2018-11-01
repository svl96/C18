#include <stdio.h>
#include <stdlib.h>

// хорошее использование макроса

// Задача с перемножением матриц. 
// НА стеке заводится их произведение

// перемножение
// вывод

// написать тоже самое, но память выделять на куче
// надо проверять что память выделилась
// почистить память
// на первую хватило на вторую не хватило
// провреять каждый malloc
// без дублирования внутри себя. 

#define ARRAY_SIZE(x) (sizeof(x) / sizeof(x[0]))

#define MATRIX_INT_SIZE(n, m) (n * m * sizeof(int))

#define MTR_INDEX(n, m, i, j) (i * m + j)

#define CHECK_OR_GOTO(label, val) \
  if (!(val)) goto label

void init_line(int *h, unsigned line, int len, ...) {
  int *xs = h
  va_list args;
  va_start(args, len);

  for (unsigned i = 0; i != len; ++i) {
    h[i + line] = va_arg(args, int);
  }

  va_end(args);
}


int main(void) {
  // тут выделяется память на стеке
  // нам надо выделить память на куче. 
  // как это сделать? 

  int n = 2;
  int m = 3;
  int l = 4;

  int* hx = malloc(MATRIX_INT_SIZE(n, m));
  CHECK_OR_GOTO(free_x, hx);

  int* hy = malloc(MATRIX_INT_SIZE(m, l));
  CHECK_OR_GOTO(free_y, hy);

  int* hz = malloc(MATRIX_INT_SIZE(n, l));
  CHECK_OR_GOTO(free_y, hz);

  init_line(*hx, 0, m, 1, 2, 3);
  init_line(*hx, 1, m, 4, 5, 6);

  init_line(*hy, 0, l, 5, 6, 7, 8);
  init_line(*hy, 1, l, 6, 7, 8, 9);
  init_line(*hy, 2, l, 7, 8, 9, 0);


  const int X[2][3] = {
    { 1, 2, 3 },
    { 4, 5, 6 },
  };

  const int Y[3][4] = {
    { 5, 6, 7, 8 },
    { 6, 7, 8, 9 },
    { 7, 8, 9, 0 },
  };

for (size_t i = 0; i != n; ++i) {
    for (size_t j = 0; j != l; ++j) {
      //Z[i][j] = 0;
      hz[MTR_INDEX(n, l, i, j)] = 0;
      for (size_t k = 0; k != m; ++k) {
        //Z[i][j] += X[i][k] * Y[k][j];
        hz[MTR_INDEX(n, l, i, j)] += hx[MTR_INDEX(n,m, i,k)] *
                                             hy[MTR_INDEX(m,l,k,j)];
      }
    }
  }

  int Z[ARRAY_SIZE(X)][ARRAY_SIZE(Y[0])];

  for (size_t i = 0; i != ARRAY_SIZE(X); ++i) {
    for (size_t j = 0; j != ARRAY_SIZE(Y[0]); ++j) {
      Z[i][j] = 0;
      for (size_t k = 0; k != ARRAY_SIZE(X[0]); ++k) {
        Z[i][j] += X[i][k] * Y[k][j];
      }
    }
  }

  for (size_t i = 0; i != ARRAY_SIZE(Z); ++i) {
    for (size_t j = 0; j != ARRAY_SIZE(Z[0]); ++j)
      printf("%4d%c", Z[i][j], j == ARRAY_SIZE(Z[0]) - 1 ? '\n' : ' ');
  }

  :free_z
    free(hz);
  :free_y
    free(hy);
  :free_x
    free(hx);
}
