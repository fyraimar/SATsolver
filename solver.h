#ifndef _SOLVER_H_
#define _SOLVER_H_

#include "matrix.h"

#include <iostream>
#include <fstream>

class solver {
public:
  solver(matrix &new_M);
  void is_reduce(int *isz, int *dr, int *is);
  void is_zero_row(int *izr, int *zr);
  void reduce();
  void find_a();

  //for test
  void print();
  void print_list();

private:
  matrix *m_ptr;
};

#endif
