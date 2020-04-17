#include <iostream>
#include "header.h"
#include <vector>

using namespace std;

unsigned int size_const() {

    unsigned int max_size;
    cout << "Array size:" << endl;
    cin >> max_size;
    cout << "\n------------------------------------------\n";

    return max_size;
}

vector<int> arr_fill() {

    unsigned int max_size;
    cout << "Array size:" << endl;
    cin >> max_size;

    cout << "Array elems:" << endl;
    vector<int> arr_tmp(max_size);
    for (unsigned int i = 0; i < max_size; i++) {

        int n;
        cin >> n;

        arr_tmp[i] = n;
    }
    cout << "\n------------------------------------------\n";

    return arr_tmp;
}

void s_find_elem(Int_nums &arr) {

    cout << "What elem you would like to find?" << endl;
    int num;
    cin >> num;
    if (!arr.c_find_elem(num)) {
        cout << "NO ELEM _" << num << "_";
    } else {
        cout << "YES ELEM _" << num << "_";
    }
}