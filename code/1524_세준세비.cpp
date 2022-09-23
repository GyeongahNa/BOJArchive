#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
#include <cmath>
#include <tuple>
#include <queue>
using namespace std;

using ii = pair<int, int>;

int main() {
    
    int T;
    scanf("%d", &T);
    
    while (T--) {
        
        int N, M;
        scanf("%d %d", &N, &M);
        
        int p;
        vector<ii> v;
        for (int i=0; i<N; i++) {
            scanf("%d", &p);
            v.push_back({p, 1});
        }
        for (int i=0; i<M; i++) {
            scanf("%d", &p);
            v.push_back({p, 0});
        }
        
        sort(v.begin(), v.end());
        string winner;
        if (v[v.size()-1].second) winner = "S";
        else winner = "B";
        printf("%s\n", winner.c_str());
    }
    return 0;
}