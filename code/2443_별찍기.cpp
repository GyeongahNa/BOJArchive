#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int N, star, space;

    cin >> N;
    for (int i = 0; i < N; i++) {

        star = 2 * N - 2 * i - 1;
        space = ((2 * N - 1) - star) / 2;
        for (int j = 0; j < space; j++)
            printf(" ");
        for (int j = 0; j < star; j++)
            printf("*");

        printf("\n");
    }

    return 0;
}