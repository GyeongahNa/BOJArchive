#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
#include <cmath>
#include <tuple>
#include <queue>
using namespace std;

int main() {

    int N, A, B, C;
    scanf("%d\n%d %d\n%d", &N, &A, &B, &C);
    
    vector<int> d(N);
    for (int i=0; i<N; i++)
        scanf("%d", &d[i]);
    
    sort(d.begin(), d.end(), greater<int>());
    int re = C/A, cal = C;
    for (int i=0; i<N; i++) {
        cal += d[i];
        re = max(re, cal/(A+(i+1)*B));
    }
    printf("%d", re);
    return 0;
}