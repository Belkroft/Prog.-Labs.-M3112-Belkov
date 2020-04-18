#include <iostream>

using namespace std;

template <typename T>
void func( T &num1 , T &num2 ) {
    if (num1 > num2) {
        cout << num2 << endl;
    } else {
        cout << num1 << endl;
    }
}

int main() {

    int a1, a2;
    float b1, b2;

    cout << "Enter nums:" << endl;
    cin >> a1 >> a2;
    cin >> b1 >> b2;

    cout << "For int: ";
    func(a1, a2);

    cout << "For float: ";
    func(b1, b2);

    return 0;
}