#include "matrix.h"

#include <iostream>
#include <fstream>

int is_reduced(matrix M) {
  int m = M.get_row();
  int n = M.get_col();
  int flag = 0;
  int temp = 0;
  int rij = 0;

  for (int j = 1; j <= n; j++) {
    temp = 0;
    flag = 0;

    for (int i = 1; i <=m; i++) {
      rij = M.get_value(i,j);

      if (rij != 0) {
        if (temp == 0) {
          temp = rij;
          continue;
        }

        if (temp ^ rij > 0) {
          flag = 0;
          continue;
        }

        flag = 1;
        break;
      }
    }

    if (flag == 1)
      break;
  }

  return flag;
}

int is_same_symbol(matrix M) {
  int m = M.get_row();
  int n = M.get_col();
  int rij = 0;
  int flag = 0;
  int temp = 0;

  for (int j = 1; j <= n; j++) {
    temp = 0;
    flag = 0;

    for (int i = 1; i<= m; i++) {
      rij = M.get_value(i,j);

      if (rij == 0) {
        flag = 1;
        break;
      }
      if (temp == 0) {
        temp = rij;
        continue;
      }

      if (temp ^ rij > 0) {
        flag = 0;
        continue;
      }

      flag = 1;
      break;
    }

    if (flag == 0)
        break;
  }

  return flag;
}

int is_deduce_zero(matrix M) {
  int m = M.get_row();
  int n = M.get_col();
  int rig = 0;
  int flag = 0;
  int temp = 0;

  if (is_same_symbol(M) == 0) {
    return flag;
  } else if (is_reduced(M) == 0) {
    return flag;
  } else {
    flag = 1;
    return flag;
  }
}

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
      M.add_new_node(i, tmp, 1);
    if (tmp < 0) 
      M.add_new_node(i, -tmp, -1);
    } while (tmp != 0);
  }
  M.print();

  M.change_value(3, 3, 7);
  M.print();

  M[1][1] = 0;
  M.print();

  M[2][2] =  M[2][4] + M[1][3];
  M.print();

  M[1][1] = 3;
  M.print();

  M.print_list();

  M.delete_zero_col(3);
  M.print();

  matrix T(M);
  T.delete_zero_col(2);
  T.print();
  T.print_list();

  return 0;
}

