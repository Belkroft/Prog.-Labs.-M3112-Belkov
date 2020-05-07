#include <iostream>
#include <vector>

template <class InputIt, class UnaryPredicate>
bool all_of(InputIt first, InputIt last, UnaryPredicate p) {
    for (; first != last; ++first) {
        if (!p(*first)) return false;
    }
    return true;
}

int main() {

    unsigned short N;
    std::cout << "Vector size:" << std::endl;
    std::cin >> N;

    std::vector<short> v(N);
    std::cout << "Elem:" << std::endl;
    for (unsigned short i = 0; i < N; i++) {
        short n;
        std::cin >> n;
        v.push_back(n);
    }

    if (all_of(v.cbegin(), v.cend(), [](short num) { return num % 2 == 0; })) {
        std::cout << "TRUE" << std::endl;
    } else {
        std::cout << "FALSE" << std::endl;
    }

    return 0;
}
