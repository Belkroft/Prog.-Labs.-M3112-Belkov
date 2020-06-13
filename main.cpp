#include <iostream>
#include <algorithm>
#include "circ_buff.hpp"

int main() {

    std::cout << std::endl;
    circ_buff<short> buff(10); // size 10

    std::cout << "----------------------------TO BACK BUFF (9)----------------------------" << std::endl;
    for (short i = 0; i < 10; i++) {
        buff.push_back(i);
    }
    for (short i : buff) {
        std::cout << i << " ";
    }

    std::cout << "\n----------------------------TO FRONT BUFF (-1)--------------------------" << std::endl;
    buff.push_front(-1);
    for (unsigned long long i = 0; i < buff.size() + 1; i++) {
        std::cout << buff[i] << " ";
    }

    std::cout << "\n----------------------------DELETE BACK---------------------------------" << std::endl;
    buff.pop_back();
    for (unsigned long long i = 0; i < buff.size() + 1; i++) {
        std::cout << buff[i] << " ";
    }

    std::cout << "\n----------------------------DELETE FRONT--------------------------------" << std::endl;
    buff.pop_front();
    std::cout << "   ";
    for (unsigned long long i = 0; i < buff.size() + 1; i++) {
        std::cout << buff[i] << " ";
    }

    std::cout << "\n----------------------------SIZE (3)------------------------------------" << std::endl;
    buff.resize(3);
    for (short i : buff) {
        std::cout << i << " ";
    }

    std::cout << "\n----------------------------TO RAND (2 -> -1)---------------------------" << std::endl;
    auto elem = buff.begin() + 2;
    buff.insert(elem, -1);
    for (unsigned long long i = 0; i < buff.size() + 1; i++) {
        std::cout << buff[i] << " ";
    }

    std::cout << "\n----------------------------DELETE RAND (2)-----------------------------" << std::endl;
    buff.erase(elem);
    for (unsigned long long i = 0; i < buff.size() + 1; i++) {
        std::cout << buff[i] << " ";
    }

    std::cout << "\n----------------------------ALGORITHMS----------------------------------" << std::endl;

    std::cout << "SORTING ";
    std::sort(buff.begin(), buff.end());
    for (short i : buff) {
        std::cout << i << " ";
    }

    std::cout << "Reverse: ";
    std::reverse(buff.begin(), buff.end());
    for (int i : buff) {
        std::cout << i << " ";
    }



    return 0;
}