#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

int main() {

    int X, N;
    scanf("%d %d", &X, &N);

    if (N!= 1 && N%2 == 1)
        printf("ERROR\n");
    else if ((0 > X && N == 1) || (X > 0 && N == 0))
        printf("INFINITE\n");
    else if (X > 0 && N != 0 && N%2 == 0) {
        int nOp = N/2;
        printf("%d\n", (X+nOp-1)/nOp-1);
    }
    else printf("0\n");
    return 0;
}

//TC

// -100 0
// 0

// -100 10
// 0

// 0 0
// 0

// 0 10 
// 0

// 1 0
// INFINITE

// 100 0
// INFINITE

// 100 10
// 19

// 9 4
// 4

//10 0
//INFINITE

// -10 1 
// INFINITE

