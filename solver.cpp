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
        if (temp * rij >= 0) {
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

void solver::reduce() {
  int m = m_ptr->get_row();
  int n = m_ptr->get_col();

  int izr, zr, isz, dr, is;
  is_zero_row(&izr, &zr);
  is_reduce(&isz, &dr, &is);

  if (is == 1 && isz == 1) {
    m_ptr->print();
    return;
  }

  int add_pos = m + 1;
  for (int i = 1; i <= m ; i++) {
    if (m_ptr->get_value(i, dr) > 0) {
      for (int j = 1; j <= m; j++) {
        if (m_ptr->get_value(j, dr) < 0) {

          m_ptr->add_new_row(add_pos);
          std::set<int>::iterator iter;
          for (iter = (*m_ptr)[j].parents_list->begin(); iter != (*m_ptr)[j].parents_list->end(); iter++) {
            (*m_ptr)[add_pos].add_parent(*iter);
          }
          for (iter = (*m_ptr)[i].parents_list->begin(); iter != (*m_ptr)[i].parents_list->end(); iter++) {
            (*m_ptr)[add_pos].add_parent(*iter);
          }

          int ridr = m_ptr->get_value(i, dr);
          int rjdr = -m_ptr->get_value(j, dr);

          if (ridr > rjdr) {
            for (int k = 1; k <= n; k++) {
              int rik = m_ptr->get_value(i, k);
              int rjk = m_ptr->get_value(j, k);
              m_ptr->add_new_node(add_pos, k, rjk * ridr / rjdr + rik);
            }
          } else if (ridr < rjdr) {
            for (int k = 1; k <= n; k++) {
              int rik = m_ptr->get_value(i, k);
              int rjk = m_ptr->get_value(j, k);
              m_ptr->add_new_node(add_pos, k, rik * rjdr / ridr + rjk);
            }
          } else {
            for (int k = 1; k <= n; k++) {
              int rik = m_ptr->get_value(i, k);
              int rjk = m_ptr->get_value(j, k);
              m_ptr->add_new_node(add_pos, k, rjk + rik);
            }
          }

          add_pos++;
        }
      }

   //   m_ptr->del_row(i);

   //   m--;
    //  add_pos--;
    }
  }
  add_pos--;
  m_ptr->row_counter = add_pos ;
  m_ptr->print();
  for (int i = 1; i <= add_pos; i++) {
    if (m_ptr->get_value(i, dr) != 0) {
      m_ptr->del_row(i);
      add_pos--;
      i--;
    }
  }
  m_ptr->row_counter = add_pos;
//m_ptr->del_col(dr);
//m_ptr->row_counter--;
  m_ptr->print();
//  m_ptr->print_list();
}

void solver::find_a() {
  int m = m_ptr->get_row();
  int n = m_ptr->get_col();

  int iz = 0;

  matrix B(*m_ptr);
  for (;;) {
    matrix R(*m_ptr);

    for (int k = n - 1; k >= 0; k--) {
      if (1);

      for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
          }
      }
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

