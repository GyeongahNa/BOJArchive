#include <iostream>

int main() {

    long N, K, tmp;
    long course[100000];

    std::cin >> N >> K;
    for (int i = 0; i < N; i++)
        std::cin >> course[i];

    tmp = 0;
    for (int i = 0; i < N; i++) {
        tmp += course[i];
        if (tmp > K) {
            std::cout << i + 1 <<std::endl;
            return 0;
        }
    }

    for (int i = N - 1; i >= 0; i--) {
        tmp += course[i];
        if (tmp > K) {
            std::cout << i + 1 << std::endl;
            return 0;
        }
    }
    return 0;
}