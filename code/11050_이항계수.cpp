#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
using namespace std;

int factorial(int n) {
    
    if (n == 0 || n == 1)
        return 1;
    return n * factorial(n -1);
}

int main() {

    int N, K, res;

    cin >> N >> K;
    res = factorial(N) / (factorial(K) * factorial(N - K));
    printf("%d\n", res);
    return 0;
}