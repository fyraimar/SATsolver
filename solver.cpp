#include "matrix.h"

#include <iostream>
#include <fstream>

int main() {
  int var_num, sen_num;
  std::ifstream in;
  in.open("testdata");
  in >> var_num >> sen_num;
  matrix M(var_num, sen_num);
  for (int i = 1; i <= sen_num; i++) {
    int tmp = 0;

    do {
      in >> tmp;
    if (tmp > 0)
      M.set_value(i, tmp, 1);
    if (tmp < 0) 
      M.set_value(i, -tmp, -1);
    } while (tmp != 0);
  }
  M.print();

  return 0;
}

