#ifndef LAB3_2_HEADER_H
#define LAB3_2_HEADER_H

#include <iostream>
#include <string>
#include <queue>

using namespace std;

string name_enter();
string operation();

class Queue {
private:
    string name;
    queue <int> q;
public:

    Queue(); // empty
    Queue(const string &add_name); // for queue

    void operator<<(const int &add_num);
    int operator>>(const string &operation);

    void show_q();

};

#endif //LAB3_2_HEADER_H
