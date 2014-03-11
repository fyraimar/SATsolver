#include <iostream>

using namespace std;

int origin_data[4][4] = {1, 0, 1, 1,
                         -1, 1, 0, -1,
                         1, 0, -1, 1,
                         0, 0, 1, -1};
int col_num = 4;
int row_num = 4;

bool reduce() {
    if (col_num == 1 || row_num == 1)
        return false;

    int col_ptr = col_num;
    //int row_ptr = 0;
    int pos_counter;
    int neg_counter;

    bool if_col_reducable = false;
    while (!if_col_reducable) {
        col_ptr--;
        pos_counter = 0;
        neg_counter = 0;
        for (int i = 0; i < row_num; i++) {
            if (origin_data[i][col_ptr] > 0)
                pos_counter++;
            if (origin_data[i][col_ptr] < 0)
                neg_counter++;
        }
        if (pos_counter > 0 && neg_counter > 0)
            if_col_reducable =true;
    }

    if (col_ptr < 0)
        return false;

    for (int p = 0; p < row_num; p++) {
        for (int q = row_num + 1; q < row_num; q++) {
            if (origin_data[p][col_ptr] * origin_data[q][col_ptr] < 0) {
            }
        }
    }

    return true;
}

void print() {
    for (int p = 0; p < row_num; p++) {
        for ( int q = 0; q < col_num; q++) {
            cout << origin_data[p][q] << " ";
        }
        cout << endl;
    }
    cout << "-------------------------------------" << endl;
}

int main() {
    while (reduce(origin_data, col_num, row_num)) {
        print();
    }

    print();
    return 0;
}

