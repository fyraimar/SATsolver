#include "matrix.h"

#include <iostream>

/* The implement of class node */
node::node(int new_col_num, int new_value) {
  col_num = new_col_num;
  value = new_value;
}

/* The implement of class row */
row::row(int new_row_num) {
  row_num = new_row_num;
  node_list = new list<node>;
  
  node_list->clear();
}

int row::get_row_num() {
  return row_num;
}

void row::add_node(int new_col_num, int new_value) {
  node new_node(new_col_num, new_value);
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

void row::delete_col(int col_num) {
  list<node>::iterator iter;
  for (iter = node_list->begin(); iter != node_list->end(); ++iter) {
    if (iter->col_num > col_num) {
      iter->col_num--;
    }
  }
}


  
  

/* The implement of class row */
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

