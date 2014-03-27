#include <list>

using std::list;

class node {
private:
  int x;
  int y;
  int value;

public:
  node(int nex_x, int new_y, int new_value);
  int get_x();
  int get_y();
  int get_value();
  bool change_value(int new_value);
};

class matrix {
private:
  list<node>* matrix_list;
  int col;
  int row;

public:
  matrix(int new_col, int new_row);
  void set_value(int pos_x, int pos_y, int new_value);
  void print();
  int get_col();
  int get_row();
  int get_value(int pos_x, int pos_y);
  bool change_value(int pos_x, int pos_y, int new_value);
};

