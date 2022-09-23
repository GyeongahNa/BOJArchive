#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
using namespace std;

int main() {
    int N;
    long long* div;

    cin >> N;
    div = new long long[N];
    for (int i = 0; i < N; i++)
        cin >> div[i];
    
    sort(div, div + N);
    if (N % 2 == 0)
        printf("%lld\n", div[0] * div[N - 1]);
    else
        printf("%lld\n", div[N / 2] * div[N / 2]);
    return 0;
}