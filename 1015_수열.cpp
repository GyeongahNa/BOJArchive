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

    vector<int> vA(N), vB(N), vP(N);
    for (int i=0; i < N; i++) {
        int n;
        scanf("%d", &n);
        vA[i]=n;
        vB[i]=n;
    }
    sort(vB.begin(), vB.end());
    
    for (int i=0; i < N; i++) {
        int idx = find(vB.begin(), vB.end(), vA[i]) - vB.begin();
        vB[idx]=-1;
        vP[i]=idx;
    }

    for (int i=0; i < N; i++)
        printf("%d ", vP[i]);
    return 0;
}
