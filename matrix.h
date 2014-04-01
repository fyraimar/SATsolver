#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <list>
#include <set>

using std::list;
using std::set;

class row;

class node {
public:
  int col_num;
  int value;
  row* belonged_row;

  node(int new_col_num, int new_value, row* belonged_row);
  node(const node& other_node, row* belonged_row);

  void operator=(int new_value);
  void operator=(node& other_node);
  node& operator+(node& other_node);
};

class row {
private:
  int row_num;
  set<int>* parents_list;

public:
  list<node>* node_list;

  row(int new_row_num);
  row(const row& other_row);

  int get_row_num();

  void add_node(int new_col_num, int new_value);
  int get_node_value(int col_num);
  void delete_node(int col_num);
  void change_node_value(int col_num, int new_value);

  void delete_col(int col_num);

  void add_parent(int row_num);

  node& operator[](int col_num);
};
 

class matrix {
private:
  list<row>* row_list;
  int col_counter;
  int row_counter;

public:
  matrix(int new_col, int new_row);
  matrix(const matrix& other_matrix);

  void add_new_row(int new_row_num);
  void add_new_node(int new_row_num, int new_col_num, int new_value);

  int get_col();
  int get_row();
  bool delete_zero_col(int col_num);

  int get_value(int row_num, int col_num);
  void change_value(int row_num, int col_num, int new_value);

  void print();
  void print_list();

  row& operator[](int row_num);
};

#endif
