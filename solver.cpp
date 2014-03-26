#include "matrix.h"

#include <iostream>

int main() {
  int var_num, sen_num;
  std::cin >> var_num >> sen_num;
  matrix M(var_num, sen_num);
  for (int i = 1; i <= sen_num; i++) {
    int tmp = 0;

    do {
    std::cin >> tmp;
    if (tmp > 0)
      M.set_value(i, tmp, 1);
    if (tmp < 0) 
      M.set_value(i, -tmp, -1);
    } while (tmp != 0);
  }
  M.print();

  return 0;
}

