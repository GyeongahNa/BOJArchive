#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

int main() {

    int N, numBlank;

    cin >> N;
    for (int i = N-1; i >= 1; i--) {
        for (int j = 1; j <= N-i; j++)
            printf("*");
        for (int j = 1; j <= 2*i; j++)
            printf(" ");
        for (int j = 1; j <= N-i; j++)
            printf("*");
        printf("\n");
    }
    for (int i = 1; i <= 2*N; i++)
        printf("*");
    printf("\n");
    for (int i = 1; i <= N-1; i++) {
        for (int j = 1; j <= N-i; j++)
            printf("*");
        for (int j = 1; j <= 2*i; j++)
            printf(" ");
        for (int j = 1; j <= N-i; j++)
            printf("*");
        printf("\n");
    }

    return 0;
}