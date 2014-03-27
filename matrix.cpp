#include "matrix.h"

#include <iostream>

node::node(int new_x, int new_y, int new_value) {
  x = new_x;
  y = new_y;
  value = new_value;
}

int node::get_x() {
  return x;
}

int node::get_y() {
  return y;
}

int node::get_value() {
  return value;
}

bool node::change_value(int new_value) {
  value = new_value;
}

matrix::matrix(int new_col, int new_row) {
  col = new_col;
  row = new_row;
  matrix_list = new list<node>;
}

void matrix::set_value(int pos_x, int pos_y, int new_value) {
    if (new_value == 0)
      return;
    node* new_node = new node(pos_x, pos_y, new_value);
    matrix_list->push_back(*new_node);
}

int matrix::get_value(int pos_x, int pos_y) {
  list<node>::iterator iter;
  for (iter = matrix_list->begin(); iter != matrix_list->end(); ++iter) {
      if (iter->get_x() == pos_x && iter->get_y() == pos_y) {
          return iter->get_value();
      }
  }

  return 0;
}

int matrix::get_col() {
  return col;
}

int matrix::get_row() {
  return row;
}

void matrix::print() {
  std::cout << "----------------------start\n";
  for (int p = 1; p <= row; p++) {
    for (int q = 1; q <= col; q++) {
      std::cout << get_value(p, q) << " ";
    }
    std::cout << std::endl;
  }
  std::cout << "------------------------end\n";
}

bool matrix::change_value(int pos_x, int pos_y, int new_value) {
  if (get_value(pos_x, pos_y) == 0) {
    if (new_value != 0) {
      node* new_node = new node(pos_x, pos_y, new_value);
      matrix_list->push_back(*new_node);
    }
    return true;
  }

  list<node>::iterator iter;
  for (iter = matrix_list->begin(); iter != matrix_list->end(); ++iter) {
    if (iter->get_x() == pos_x && iter->get_y() == pos_y) {
      if (new_value == 0)
        matrix_list->erase(iter);
      else iter->change_value(new_value);
        return true;
    }
  }
  return false;
}

