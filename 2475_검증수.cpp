#include <iostream>
#include <cmath>

int main() {

    int n1, n2, n3, n4, n5;

    std::cin >> n1 >> n2 >> n3 >> n4 >> n5;
    std::cout << int(pow(n1, 2) + pow(n2, 2) + pow(n3, 2) + pow(n4, 2) + pow(n5, 2)) % 10 << std::endl;

    return 0;
}