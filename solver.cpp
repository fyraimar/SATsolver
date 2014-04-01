#include "solver.h"

solver::solver(matrix &new_M) {
  m_ptr = new matrix(new_M);
}

void solver::is_reduce(int *isz, int *dr, int *is) {
  *dr = -1;
  *isz = 1;
  *is = 0;

  int iz;
  int flag;
  int n = m_ptr->get_col();
  int m = m_ptr->get_row();

  for (int j = 1; j <= n; j++) {
    iz = 0;
    int temp = 0;
    flag = 0;

    for (int i = 1; i <= m; i++) {
      int rij = m_ptr->get_value(i, j);
      if (rij == 0) {
        iz = 1;
      } else {
        if (temp == 0) {
          temp = rij;
          flag = 1;
          continue;
        }
        if (temp ^ rij >= 0) {
          flag = 1;
          continue;
        } else {
          flag = 0;
          break;
        }
      }
    }

    if (flag == 0) {
      *dr = j;
    }
    if (iz == 0 && flag == 1) {
      *is = 1;
      break;
    } else if (iz == 1 && flag == 1) {
      continue;
    } else {
      *isz = 0;
    }
  }
}

void solver::is_zero_row(int *izr, int *zr) {
  int m = m_ptr->get_row();
  int n = m_ptr->get_col();
  *izr = 0;

  for (int i = 1; i <= m; i++) {
    *izr = 0;
    if (m_ptr->get_value(i, 1) == 0) {
      for (int j = 1; j <= n; j++) {
        if (m_ptr->get_value(i, j) != 0) {
          *izr = 0;
          break;
        } else {
          *izr = 1;
        }
      }
    } else {
      continue;
    }

    if (*izr == 1) {
      *zr = i;
      break;
    }
  }
}

void solver::print() {
  m_ptr->print();
}

void solver::print_list() {
  m_ptr->print_list();
}

