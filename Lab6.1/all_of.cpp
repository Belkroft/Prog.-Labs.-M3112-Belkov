#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include "point.hpp"
#include "pointc.cpp"

template <class InputIt, class UnaryPredicate>
bool all_of(InputIt first, InputIt last, UnaryPredicate p) {
    for (; first != last; ++first) {
        if (!p(*first)) return false;
    }
    return true;
}

int main() {

    std::vector<int> v{1, 2, 3, 4, 5};
    std::string str{"radar"};
    std::queue<float> q;
    for (int i = 0; i < 5; i++)
        q.push(i);
    std::vector<CVector3D> v2{{{0, 0}, {2, 2}}, {{1, 5}, {6, -2}}, {{5, 3}, {-5, -2}}, {{2, 0}, {6, 0}}};
    std::cout << "Vector:" << std::endl;
    print(v.begin(), v.end());
    std::cout << "all_of < 6\t: " << all_of(v.begin(), v.end(), cmp) << std::endl;

    return 0;
}
