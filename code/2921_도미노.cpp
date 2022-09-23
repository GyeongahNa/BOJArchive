#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

int main() {

    int N, res;

    scanf("%d", &N);
    res=0;
    for (int i=0; i<=N-1; i++) {
        for (int j=i+1; j<=N; j++)
            res+=(i+j);
    }
    for (int i=1; i<=N; i++)
        res+=i*2;
    printf("%d\n", res);
    return 0;
}