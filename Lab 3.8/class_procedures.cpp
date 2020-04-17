#include <iostream>
#include <queue>
#include <string>
#include "header.h"

using namespace std;

Queue::Queue() { // empty
    this->q = {};
}
Queue::Queue(const string &add_name) { // NORMAL constructor

    this->name = add_name;

    cout << "Queue size:" << endl;
    unsigned int size;
    cin >> size;
    if (size > 100) {
        cout << "ERROR" << endl;
        exit(0);
    }

    cout << "Queue elems:" << endl;
    for (unsigned int i = 0; i < size; i++) {
        int num;
        cin >> num;
        this->q.push(num);
    }

    show_q();
}

void Queue::operator<<(const int &add_num) {
    this->q.push(add_num);
    show_q();

}
int Queue::operator>>(const string &operation) {

    if (operation != ">>") {
        return false;
    }

    int num = this->q.front();
    this->q.pop();
    cout << num;

    return num;
}

void Queue::show_q() {

    cout << "QUEUE NAME: " << this->name << endl;
    cout << "ELEMS:" << endl;

    queue<int> q_tmp;
    while(!this->q.empty()) {
        int num = this->q.front();
        q_tmp.push(this->q.front());
        this->q.pop();
        cout << num << " ";
    }
    cout << endl;

    while(!q_tmp.empty()) {
        this->q.push(q_tmp.front());
        q_tmp.pop();
    }

}
