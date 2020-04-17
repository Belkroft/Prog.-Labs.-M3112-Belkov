#include <iostream>
#include "header.h"
#include <algorithm>
#include <vector>

using namespace std;

Int_nums::Int_nums() { // empty constructor
    this->nums.resize(0);
}
Int_nums::Int_nums(unsigned int add_size) { // SIZE constructor

    this->nums.resize(add_size);
    for (unsigned int i = 0; i < add_size; i++) {
        this->nums[i] = 0;
    }
    show_array();
}
Int_nums::Int_nums(vector<int> add_nums) { //NORMAL constructor

    for (unsigned long long i = 0; i < add_nums.size(); i++) {
        this->nums.push_back(add_nums[i]);
    }
    show_array();
}
Int_nums::Int_nums(const Int_nums &c_arr) { // COPY constructor

    for (unsigned long long i = 0; i < c_arr.nums.size(); i++) {
        this->nums.push_back(c_arr.nums[i]);
    }
    show_array();
}

Int_nums Int_nums::operator+(const int &num) {

    this->nums.push_back(num);
    return *this;
}
Int_nums Int_nums::operator-(const int &num) {

    unsigned long long size = this->nums.size(); // size RIGHT NOW
    bool check = false;
    for (unsigned long long i = 0; i < this->nums.size(); i++) {

      if (!check and this->nums[i] == num) {
          this->nums.erase(this->nums.begin() + i);
          check = true;
      }
    }

    if (size == this->nums.size()) {
      cout << "NO ELEM _" << num << "_" << endl;
    }

    return *this;
}

Int_nums Int_nums::operator&&(const Int_nums &arr_right) {
    Int_nums new_arr;

    set_intersection(this->nums.begin(), this->nums.end(),
                     arr_right.nums.begin(), arr_right.nums.end(),
                     back_inserter(new_arr.nums));

    cout << "New array (&&):" << endl;
    new_arr.show_array();
    return new_arr;
}
Int_nums Int_nums::operator||(const Int_nums &arr_right) {
    Int_nums new_arr;

    set_union(this->nums.begin(), this->nums.end(),
                     arr_right.nums.begin(), arr_right.nums.end(),
                     back_inserter(new_arr.nums));

    cout << "New array (||):" << endl;
    new_arr.show_array();
    return new_arr;
}

Int_nums Int_nums::operator+(const Int_nums &arr_right){

    for (unsigned long long i = 0; i < arr_right.nums.size(); i++) {
        this->nums.push_back(arr_right.nums[i]);
    }

    return *this;
}
Int_nums Int_nums::operator-(const Int_nums &arr_right) {

    for (unsigned long long i = 0; i < arr_right.nums.size(); i++) {

        int num = arr_right.nums[i];
        bool check = false;

        for (unsigned long long j = 0; j < this->nums.size(); j++) {
            if (!check and this->nums[j] == num) {
                this->nums.erase(this->nums.begin() + j);
                check = true;
            }
        }
    }

    return *this;
}

bool Int_nums::c_find_elem(int &num) {

    for (unsigned long long i = 0; i < this->nums.size(); i++) {
        if (this->nums[i] == num) {
            return true;
        }
    }
    return false;
}
void Int_nums::show_array() {
    cout << "SIZE:" << " " << this->nums.size() << endl;
    cout << "ELEMS:" << endl;
    for (unsigned long long i = 0; i < this->nums.size(); i++) {
        cout << this->nums[i] << " ";
    }
    cout << "\n------------------------------------------\n";
}