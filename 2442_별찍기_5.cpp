#include <iostream>
#include <cstdio>
using namespace std;

int main() {

    int N, star, space;

    cin >> N;
    for (int i = 1; i <= N; i++) {

        star = 2 * i - 1;
        space = ((2 * N - 1) - star) / 2;
        for (int i = 1; i <= space; i++)
            printf(" ");
        for (int i = 1; i <= star; i++)
            printf("*");
        printf("\n");
    }

    return 0;
}