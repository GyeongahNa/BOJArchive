#include <iostream>

int main() {

    int a, b, c;
    int A, B, C;
    int x, y, z;

    std::cin >> a >> b >> c;
    std::cin >> x >> y >> z;
    
    A = x - c;
    B = y / b;
    C = z - a;

    std::cout << A << " " << B << " " << C << std::endl;
    return 0;
}