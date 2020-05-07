#ifndef LAB3_HEADER_H
#define LAB3_HEADER_H

#include <iostream>
#include <string>

using namespace std;

string name_enter();

class Matrix {
private:
    string name;
    int matrix[3][3];
public:

    Matrix(); // ZERO constructor
    Matrix(const string &add_name); // NORMAL constructor

    Matrix operator+(const Matrix &matrix_right); // matrix + matrix
    Matrix operator-(const Matrix &matrix_right); // matrix - matrix

    Matrix operator*=(const int &num); // matrix * num
    Matrix operator*(const Matrix &matrix_right); // matrix * matrix

    bool operator==(const Matrix &matrix_right);
    bool operator!=(const Matrix &matrix_right);

    bool operator>(Matrix &matrix_right);
    bool operator<(Matrix &matrix_right);

    int deter(int (&matrix)[3][3]);
    void show_matrix();
};

#endif 
