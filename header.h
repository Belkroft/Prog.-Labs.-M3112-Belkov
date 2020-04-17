#ifndef LAB2_1_HEADER_H
#define LAB2_1_HEADER_H

#include <iostream>
#include <vector>


using namespace std;

unsigned int size_const();
vector<int> arr_fill();

class Int_nums {
private:

    vector<int> nums;

public:
    Int_nums(); // EMPTY const
    Int_nums(unsigned int add_size); // MAX_SIZE const
    Int_nums(vector<int> add_nums); // NORMAL const
    Int_nums(const Int_nums &c_arr); // COPY const

    Int_nums operator+(const int &num);
    Int_nums operator-(const int &num);

    Int_nums operator&&(const Int_nums &arr_right);
    Int_nums operator||(const Int_nums &arr_right);

    Int_nums operator+(const Int_nums &arr_right);
    Int_nums operator-(const Int_nums &arr_right);

    bool c_find_elem(int &num);
    void show_array();

};

void s_find_elem(Int_nums &arr);

#endif //LAB2_1_HEADER_H
