#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

int main() {

    long N, res;

    cin >> N;
    res=0;
    for (int i=1; i<=N; i++)
        res+=5*i;
    for (int i=1; i<=N-1; i++)
        res+=(-2*i-1);
    printf("%lld\n", res % 45678);
    return 0;
}