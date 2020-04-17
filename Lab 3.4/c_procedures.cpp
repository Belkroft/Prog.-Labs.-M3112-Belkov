#include <iostream>
#include <string>
#include "header.h"

using namespace std;

Matrix::Matrix() { // ZERO constructor
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            this->matrix[i][j] = 0;
        }
    }
}
Matrix::Matrix(const string &add_name) { // NORMAL constructor

    this->name = add_name;
    cout << "Matrix elems:" << endl;
    int num;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> num;
            this->matrix[i][j] = num;
        }
    }
    show_matrix();
}

Matrix Matrix::operator+(const Matrix &matrix_right) { // matrix + matrix
    Matrix new_matrix;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            new_matrix.matrix[i][j] = this->matrix[i][j] + matrix_right.matrix[i][j];
        }
    }

    new_matrix.show_matrix();
    return new_matrix;
}
Matrix Matrix::operator-(const Matrix &matrix_right) { // matrix - matrix
    Matrix new_matrix;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            new_matrix.matrix[i][j] = this->matrix[i][j] - matrix_right.matrix[i][j];
        }
    }

    new_matrix.show_matrix();
    return new_matrix;
}

Matrix Matrix::operator*=(const int &num) { // matrix * num

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            this->matrix[i][j] *= num;
        }
    }

    show_matrix();
    return *this;
}
Matrix Matrix::operator*(const Matrix &matrix_right) { // matrix * matrix

    Matrix new_matrix;
    new_matrix.name = name_enter();

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            new_matrix.matrix[i][j] = 0;
            for (int k = 0; k < 3; k++) {
                new_matrix.matrix[i][j] += matrix[i][k] * matrix_right.matrix[k][j];
            }
        }
    }

    new_matrix.show_matrix();
    return new_matrix;
}

bool Matrix::operator==(const Matrix &matrix_right) {

    bool check = true;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (this->matrix[i][j] != matrix_right.matrix[i][j]) {
                check = false;
                break;
            }
        }
    }

    return check;
}
bool Matrix::operator!=(const Matrix &matrix_right) {

    bool check = false;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (this->matrix[i][j] != matrix_right.matrix[i][j]) {
                check = true;
                break;
            }
        }
    }

    return check;
}

bool Matrix::operator>(Matrix &matrix_right) {
    int d1 = deter(this->matrix);
    int d2 = deter(matrix_right.matrix);

    if (d1 > d2) {
        return true;
    } else {
        return false;
    }
}
bool Matrix::operator<(Matrix &matrix_right) {
    int d1 = deter(this->matrix);
    int d2 = deter(matrix_right.matrix);

    if (d1 > d2) {
        return false;
    } else {
        return true;
    }
}

int Matrix::deter(int (&add_matrix)[3][3]) {
    int det = add_matrix[0][0] * add_matrix[1][1] * add_matrix[2][2] - add_matrix[0][0] * add_matrix[1][2] * add_matrix[2][1]
              - add_matrix[0][1] * add_matrix[1][0] * add_matrix[2][2] + add_matrix[0][1] * add_matrix[1][2] * add_matrix[2][0]
              + add_matrix[0][2] * add_matrix[1][0] * add_matrix[2][1] - add_matrix[0][2] * add_matrix[1][1] * add_matrix[2][0];
    return det;
}
void Matrix::show_matrix() {
    cout << "---------------------------------------" << endl;
    cout << "MATRIX NAME: " << this->name << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << this->matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << "---------------------------------------" << endl;
}

