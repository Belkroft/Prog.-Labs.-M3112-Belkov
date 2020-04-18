#include <iostream>
#include <queue>
#include <exception>
#include "class.h"

using namespace std;

int main() {

    queue<float> q1;
    //queue<short> q2;

    unsigned short size;
    cout << "Queue size:" << endl;
    cin >> size;

    cout << "Float queue elems:" << endl;
    for (unsigned short i = 0; i < size; i++) {
        float a;
        cin >> a;
        q1.push(a);
    }

    //cout << "Int queue elems:" << endl;
    //for (unsigned short i = 0; i < size; i++) {
        //int a;
        //cin >> a;
        //q2.push(a);
    //}

    Queue<float> q_c1(q1);
    //Queue<short> q_c2(q2);

    try {
        q_c1 >> operation(); // delete elem
        //q_c2 >> operation();
        q_c1 << 3.5; // add elem
        //q_c2 << 7;
    }
    catch (QueueException &exception) {
        cout << "Queue exception occurred (" << exception.what() << ")" << endl;
    }
    catch (exception &exception) {
        cout << "Some other exception occurred (" << exception.what() << ")" << endl;
    }

    return 0;
}
