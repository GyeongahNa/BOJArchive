#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

int main() {

    int N, dgit;

    cin >> N;
    dgit = 10;
    while (N / dgit != 0) {
        if (N % dgit >= 5 * (dgit / 10))
            N = (N / dgit + 1) * dgit;
        else N = (N / dgit) * dgit;
        dgit *= 10;
    }
    printf("%d\n", N);
    return 0;
}