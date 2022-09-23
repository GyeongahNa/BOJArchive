#include <iostream>

int main() {
 
    int ans[6] = {1, 1, 2, 2, 2, 8};
    int hav[6];

    for (int i = 0; i < 6; i++)
        std::cin >> hav[i];

    for (int i = 0; i < 6; i++) {
        std::cout << ans[i] - hav[i];
        if (i != 5)
            std::cout << " ";
    } 
    std::cout << std::endl;
    return 0;
}