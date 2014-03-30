#include <list>

using std::list;

class node {
public:
  int col_num;
  int value;

  node(int new_col_num, int new_value);
};

class row {
private:
  int row_num;
  list<node>* node_list;

public:
  row(int new_row_num);
  int get_row_num();
  void add_node(int new_col_num, int new_value);
  int get_node_value(int col_num);
  void change_node_value(int col_num, int new_value);
  void delete_col(int col_num);
};
 

class matrix {
private:
  list<row>* row_list;
  int col_counter;
  int row_counter;

public:
  matrix(int new_col, int new_row);
  void add_new_row(int new_row_num);
  void add_new_node(int new_row_num, int new_col_num, int new_value);

  void print();
  int get_col();
  int get_row();
  int get_value(int row_num, int col_num);
  void change_value(int row_num, int col_num, int new_value);
  bool delete_zero_col(int col_num);
};

