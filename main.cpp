#include "matrix.h"

int main() {
  matrix* M = new matrix(4,4);
  int data[16] = {1, 2, 0, 0,
                  3, 4, 0, 5,
                  0, 0, 6, 7,
                  0, 8, 9, 0};
  M->set_value(data);
  M->print();

  M->change_value(3, 3, 7);
  M->print();

  M->change_value(1, 0, 0);
  M->print();

  M->delete_zero_col(4);
  M->print();
  return 0;
}

