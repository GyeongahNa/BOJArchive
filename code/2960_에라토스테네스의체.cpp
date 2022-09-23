#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

//TC
//2 1
//1000 1
//1000 999

int main() {

    int N, K;
    scanf("%d %d", &N, &K);

    vector<int> v;
    for (int i=0; i<=N; i++)
        v.push_back(i);
    
    v[1]=0;

    int cnt = 0;
    int i, j;
    for (i=2; i<=N; i++) {
        if (v[i] == 0) continue;
        for (j=i; j<=N; j+=i) {
            if (v[j] == 0) continue;
            v[j] = 0;
            cnt++;
            if (cnt == K) break;
        }
        if (cnt == K) break;
    }
    printf("%d\n", j);
    return 0;
}