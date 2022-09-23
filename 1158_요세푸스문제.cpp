#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    
    int N, K, idx, jdx;
    scanf("%d %d", &N, &K);

    vector<int> v(N);
    for (int i=0; i<N; i++)
        v[i]=i+1;
    
    idx = 0;
    printf("<");
    while (true) {
        jdx=(idx+K-1)%v.size();
        printf("%d", v[jdx]);
        v.erase(v.begin()+jdx);
        if (v.size() == 0) break;
        else printf(", ");
        idx=jdx%v.size();
    }
    printf(">\n");
    return 0;
}