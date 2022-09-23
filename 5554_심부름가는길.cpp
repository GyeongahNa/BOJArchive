#include <iostream>

int main() {

    int t1, t2, t3, t4;

    std::cin >> t1 >> t2 >> t3 >> t4;
    std::cout << (t1 + t2 + t3 + t4) / 60 << std::endl;
    std::cout << (t1 + t2 + t3 + t4) % 60 << std::endl;

    return 0;
}