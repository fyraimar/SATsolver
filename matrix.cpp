#include "matrix.h"

#include <iostream>

/* The implement of class node */
node::node(int new_col_num, int new_value, row* new_belonged_row) {
  col_num = new_col_num;
  value = new_value;
  belonged_row = new_belonged_row;
}

node::node(const node& other_node, row* new_belonged_row) {
  this->col_num = other_node.col_num;
  this->value = other_node.value;
  this->belonged_row = new_belonged_row;
}

void node::operator=(int new_value) {
  if (new_value == 0) {
    belonged_row->delete_node(col_num);
  } else {
    this->value = new_value;
  }
}

void node::operator=(node& other_node) {
  if (other_node.value == 0) {
    other_node.belonged_row->delete_node(other_node.col_num);
    this->belonged_row->delete_node(this->col_num);
    return;
  }

  this->value = other_node.value;

  if (other_node.col_num == -1)
    other_node.belonged_row->delete_node(other_node.col_num);
}

node& node::operator+(node& other_node) {
  static node tmp_node(-1, this->value + other_node.value, this->belonged_row);

  if (other_node.value == 0)
    other_node.belonged_row->delete_node(other_node.col_num);

  if (this->value == 0)
    this->belonged_row->delete_node(this->col_num);

  return tmp_node;
}

/* The implement of class row */
row::row(int new_row_num) {
  row_num = new_row_num;
  
  node_list = new list<node>;
  node_list->clear();

  parents_list = new set<int>;
  parents_list-> clear();
}

row::row(const row& other_row) {
  this->row_num = other_row.row_num;

  node_list = new list<node>;

  parents_list = new set<int>;
  parents_list-> clear();
  
  list<node>::iterator iter;
  for (iter = other_row.node_list->begin(); iter != other_row.node_list->end(); ++iter) {
    node new_node(*iter,this);
    this->node_list->push_back(new_node);
  }
}


int row::get_row_num() {
  return row_num;
}

void row::add_node(int new_col_num, int new_value) {
  node new_node(new_col_num, new_value, this);
  node_list->push_back(new_node);
}

int row::get_node_value(int col_num) { 
  list<node>::iterator iter;
  for (iter = node_list->begin(); iter != node_list->end(); ++iter) {
    if (iter->col_num == col_num) {
      return iter->value;
    }
  }
  return 0;
}
 
void row::change_node_value(int col_num, int new_value) {
  int old_value = 0;
  list<node>::iterator iter;
  for (iter = node_list->begin(); iter != node_list->end(); ++iter) {
    if (iter->col_num == col_num) {
      old_value = iter->value;
      break;
    }
  }

  if (old_value == 0 && new_value == 0)
    return;

  if (old_value == 0) {
    add_node(col_num, new_value);
    return;
  }

  if (new_value == 0) {
    node_list->erase(iter);
    return;
  }

  iter->value = new_value;
}

void row::delete_node(int col_num) {
  list<node>::iterator iter;
  for (iter = node_list->begin(); iter != node_list->end(); ++iter) {
    if (iter->col_num == col_num) {
      node_list->erase(iter);
      return;
    }
  }
}

void row::delete_col(int col_num) {
  list<node>::iterator iter;
  for (iter = node_list->begin(); iter != node_list->end(); ++iter) {
    if (iter->col_num > col_num) {
      iter->col_num--;
    }
  }
}

void add_parent(int row_num) {
}
  

node& row::operator[](int col_num) {
  list<node>::iterator iter;
  for (iter = node_list->begin(); iter != node_list->end(); ++iter) {
    if (iter->col_num == col_num) {
      return *iter;
    }
  }

  node new_node(col_num, 0, this);
  node_list->push_back(new_node);
  return *(node_list->rbegin());
}

/* The implement of class matrix */
matrix::matrix(int new_col, int new_row) {
  col_counter = new_col;
  row_counter = new_row;
  row_list = new list<row>;

  row_list->clear();
  for (int i = 1; i <= row_counter; i++) {
    row new_row(i);
    row_list->push_back(new_row);
  }
}

matrix::matrix(const matrix& other_matrix) {
  this->col_counter = other_matrix.col_counter;
  this->row_counter = other_matrix.row_counter;
  this->row_list = new list<row>;

  list<row>::iterator iter;
  for (iter = other_matrix.row_list->begin(); iter != other_matrix.row_list->end(); ++iter) {
    row new_row(*iter);
    this->row_list->push_back(new_row);
  }
}

void matrix::add_new_node(int new_row_num, int new_col_num, int new_value) {
  if (new_value == 0)
    return;

  list<row>::iterator iter;
  for (iter = row_list->begin(); iter != row_list->end(); ++iter) {
    if (iter->get_row_num() == new_row_num) {
      iter->add_node(new_col_num, new_value);
      return;
    }
  }
}

int matrix::get_col() {
  return col_counter;
}

int matrix::get_row() {
  return row_counter;
}

int matrix::get_value(int row_num, int col_num) {
  list<row>::iterator iter;
  for (iter = row_list->begin(); iter != row_list->end(); ++iter) {
    if (iter->get_row_num() == row_num) {
      return iter->get_node_value(col_num);
    }
  }
}

void matrix::print() {
  std::cout << "----------------------start\n";
  for (int p = 1; p <= row_counter; p++) {
    for (int q = 1; q <= col_counter; q++) {
      std::cout << get_value(p, q) << " ";
    }
    std::cout << std::endl;
  }
  std::cout << "------------------------end\n";
}

void matrix::change_value(int row_num, int col_num, int new_value) {
  list<row>::iterator iter;
  for (iter = row_list->begin(); iter != row_list->end(); ++iter) {
    if (iter->get_row_num() == row_num) {
      iter->change_node_value(col_num, new_value);
      return;
    }
  }
}

bool matrix::delete_zero_col(int to_del_col) {
  list<row>::iterator iter;
  for (iter = row_list->begin(); iter != row_list->end(); ++iter) {
    iter->delete_col(to_del_col);
  }
  col_counter--;
  return true;
}

row& matrix::operator[](int row_num) {
  list<row>::iterator iter;
  for (iter = row_list->begin(); iter != row_list->end(); ++iter) {
    if (iter->get_row_num() == row_num) {
      return *iter;
    }
  }
}

//For test.
void matrix::print_list() {
  list<row>::iterator iter;
  list<node>::iterator iter2;
  for (iter = row_list->begin(); iter != row_list->end(); ++iter) {
    std::cout << "row #" << iter->get_row_num() << ": ";
    std::cout << "row addr: " << &(*iter) << "\n";
    for (iter2 = iter->node_list->begin(); iter2 != iter->node_list->end(); ++iter2) {
      std::cout << iter2->col_num << "|" << iter2->value << " ";
    }
    std::cout << std::endl;
  }
}

