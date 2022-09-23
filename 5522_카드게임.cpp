#include <iostream>

int main() {

    int score[5];
    int sum;

    sum = 0;
    for (int i = 0; i < 5; i++) {
        std::cin >> score[i];
        sum += score[i];
    }

    std::cout << sum << std::endl;
    return 0;
}