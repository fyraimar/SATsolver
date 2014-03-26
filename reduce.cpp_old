#include <iostream>

#define N 4

using namespace std;

int origin_data[N][N] = {1, 0, 1, 1,
                         -1, 1, 0, -1,
                         1, 0, -1, 1,
                         0, 0, 1, -1};
int res_data[N][N];
int col_num = N;
int row_num = N;

void res_to_origin() {
    for (int p = 0; p < N; p++) {
        for (int q = 0; q < N; q++) {
            origin_data[p][q] = res_data[p][q];
        }
    }
}

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

    cout << "col_ptr:" << col_ptr << endl;

    int res_row_ptr = 0;
    for (int p = 0; p < row_num; p++) {
        if (origin_data[p][col_ptr] == 0) {
            for (int q = 0; q < col_num; q++) {
                res_data[res_row_ptr][q] = origin_data[p][q];
            }
            res_row_ptr++;
            ///////////////
            cout << "res_num:" << res_row_ptr;
            //////////////
            continue;
        }

        for (int q = p + 1; q < row_num; q++) {
            if (origin_data[p][col_ptr] * origin_data[q][col_ptr] < 0) {
                for (int r = 0; r < col_num; r++) {
                    res_data[res_row_ptr][r] = origin_data[p][r] +
                                               origin_data[q][r];
                }
            }
            res_row_ptr++;
            ///////////////
            cout << "res_num:" << res_row_ptr;
            //////////////
        }
    }
    res_to_origin();

    return true;
}

void print_res() {
    for (int p = 0; p < N; p++) {
        for ( int q = 0; q < N; q++) {
            cout << res_data[p][q] << " ";
        }
        cout << endl;
    }
    cout << "-------------------------------------" << endl;
}

void print_origin() {
    for (int p = 0; p < N; p++) {
        for ( int q = 0; q < N; q++) {
            cout << origin_data[p][q] << " ";
        }
        cout << endl;
    }
    cout << "-------------------------------------" << endl;
}

int main() {
    print_origin();
    cout << "fun res:" << reduce() << endl;
    print_res();

    return 0;
}

