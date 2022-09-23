#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

int main() {

    int A, B, N;
    scanf("%d %d %d", &A, &B, &N);

    int remain=A%B;
    for (int i=0; i<N; i++) {
        remain*=10;
        if (i==N-1)
            printf("%d\n", remain/B);
        remain=remain%B;
    }
    return 0;
}