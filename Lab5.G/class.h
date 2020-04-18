#ifndef LAB5_CLASS_H
#define LAB5_CLASS_H

#include <iostream>
#include <string>
#include <queue>
#include <exception>

using namespace std;

string operation();

class QueueException: public exception {
private:
    string c_error;
public:
    QueueException(string error) : c_error(error)
    {}

    const char* what() const noexcept {
        return c_error.c_str();
    }
};

template <class T>
class Queue {
private:
    int N; // MAX SIZE
    queue <T> q; // T TYPE
public:

    Queue() {
        this->q = {};
    }

    Queue(queue<T> &add_q) {

        cout << "Max size:" << endl;
        cin >> this->N;

        while(!add_q.empty()) {
            this->q.push(add_q.front());
            add_q.pop();
        }

        show_q();
    }

    void operator<<(const T &add_elem) {

        if (this->q.size() == this->N) {
            throw QueueException("queue overflow");
        }

        this->q.push(add_elem);
        show_q();
    }

    void operator>>(const string &operation) {

        if (operation != ">>") {
            throw QueueException("error operation");
        }

        if(this->q.empty()) {
            throw QueueException("empty queue");
        }

        T elem = this->q.front();
        this->q.pop();
        cout << elem << endl;
    }

    void show_q() {

        cout << "ELEMS:" << endl;

        queue<T> q_tmp;
        while(!this->q.empty()) {
            T elem = this->q.front();
            q_tmp.push(this->q.front());
            this->q.pop();
            cout << elem << " ";
        }
        cout << endl;

        while(!q_tmp.empty()) {
            this->q.push(q_tmp.front());
            q_tmp.pop();
        }
    }
};

#endif //LAB5_CLASS_H
