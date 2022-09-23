#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
#include <cmath>
#include <tuple>
#include <queue>
using namespace std;

bool check[1000001];

int main() {
    
    int M, N;
    scanf("%d %d", &M, &N);
    memset(check, false, sizeof(check));
    
    vector<int> p;
    
    for (int i=2; i<=N; i++) {
        if (check[i]) continue;
        if (i >= M) p.push_back(i);
        for (int j=i*2; j<=N; j+=i)
            check[j] = true;
    }
    
    int sz = p.size();
    for (int i=0; i<sz; i++)
        printf("%d\n", p[i]);
    return 0;
}