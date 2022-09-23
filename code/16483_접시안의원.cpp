#include <iostream>
#include <cmath>

int main() {

    double T;

    std::cin >> T;
    std::cout << int(round(pow(0.5 * T, 2))) << std::endl;

    return 0;
}