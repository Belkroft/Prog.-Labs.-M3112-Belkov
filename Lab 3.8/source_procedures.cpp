#include <iostream>
#include <string>
#include "header.h"

string name_enter() {
    cout << "Enter queue name:" << endl;
    string name;
    cin >> name;

    return name;
}

string operation() {
    cout << "Operation:" << endl;
    string op;
    cin >> op;

    return op;
}
