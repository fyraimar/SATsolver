#include "matrix.h"
#include "solver.h"

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
      M.add_new_node(i, tmp, 1);
    if (tmp < 0) 
      M.add_new_node(i, -tmp, -1);
    } while (tmp != 0);
  }

  solver S(M);
  S.print();
  S.print_list();

  S.reduce();

  /*
  int izr, zr, isz, dr, is;
  S.is_zero_row(&izr, &zr);
  S.is_reduce(&isz, &dr, &is);

  if(izr == 1)
  {
    printf("存在0行,为第%d行\n",zr);
    return 0;
  }
  if(is == 1)
    printf("矩阵中存在一列的符号相同,不可以推导出0！\n");
  else if(isz == 1)
    printf("矩阵中每一列都由0和符号相同数组成,且不存在全为0的行，不可以推导出0！\n");
  else
    printf("矩阵中不存在符号相同的列，且存在符号相异的列，不能判断谁否能推导出0，下一步要约减的列是第%d列\n",dr);

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
  */

  return 0;
}

