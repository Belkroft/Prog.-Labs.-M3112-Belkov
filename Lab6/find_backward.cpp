#include <iostream>
#include <vector>

template <class InputIt, class T>
InputIt find_backward(InputIt first, InputIt last, const T& value) {

    //while ((first != last) && (first != --last)) {
       // swap(*first++, *last);
    //}

    for (; last != first; --last) {
        if (*last == value) {
            return last;
        }
    }
    return first;
}

int main() {

    unsigned short N;
    std::cout << "Vector size:" << std::endl;
    std::cin >> N;

    vector<short> v(N);
    std::cout << "Vector elem.:" << std::endl;
    for (unsigned short i = 0; i < N; i++) {
        short n;
        std::cin >> n;
        v.push_back(n);
    }

    short value;
    std::cout << "Element to find:" << std::endl;
    std::cin >> value;

    auto result = find_backward(v.begin(), v.end(), value);

    if (result != v.end()) {
        std::cout << "|" << value << "| in vector" << std::endl;
    } else {
        std::cout << "no |" << value << "| in vector" << std::endl;
    }

    return 0;
}