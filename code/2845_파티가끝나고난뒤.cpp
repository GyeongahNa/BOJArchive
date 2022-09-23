#include <iostream>

int main() {
    
    int n, s;
    int art[5];

    std::cin >> n >> s;
    std::cin >> art[0] >> art[1] >> art[2] >> art[3] >> art[4];

    for (int i = 0; i < 5; i++) {
        std::cout << art[i] - n * s;
        if (i != 4)
            std::cout << " ";
    }
    std::cout << std::endl;

    return 0;
}