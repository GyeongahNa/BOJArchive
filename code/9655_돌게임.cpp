#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

int main() {

    int N;
    scanf("%d", &N);

    for (int nThr=0; nThr <= N/3; nThr++) {
        
        int nOne = N-3*nThr;
        if ((nOne + nThr) % 2 == 1) {
            printf("SK\n");
            return 0;
        }
    }
    printf("CY\n");
    return 0;
}