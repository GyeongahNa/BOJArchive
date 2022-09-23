#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
#include <cmath>
#include <tuple>
using namespace std;
using ii = pair<int, int>;

void dfs(vector<vector<int>>& v, int i, int j) {

    v[i][j] = 0;

    vector<ii> dir;
    if (i > 0 && v[i-1][j] == 1) dir.push_back({-1, 0});
    if (i < (int)v.size()-1 && v[i+1][j] == 1) dir.push_back({+1, 0});
    if (j > 0 && v[i][j-1] == 1) dir.push_back({0, -1});
    if (j < (int)v[i].size()-1 && v[i][j+1] == 1) dir.push_back({0, +1});

    for (int d=0; d<dir.size(); d++) {
        int x = dir[d].first;
        int y = dir[d].second;
        if (v[i+x][j+y] == 0) continue;
        dfs(v, i+x, j+y);
    }
} 

int main() {
    
    int T;
    scanf("%d", &T);
    
    for (int t=0; t<T; t++) {
        int M, N, K;
        scanf("%d %d %d", &M, &N, &K);

        vector<vector<int>> v(N, vector<int>(M));
        for (int k=0; k<K; k++) {
            int x, y;
            scanf("%d %d", &x, &y);
            v[y][x] = 1;
        }

        int cnt = 0;
        for (int i=0; i<N; i++) {
            for (int j=0; j<M; j++) {
                if (v[i][j] == 0) continue;
                dfs(v, i, j);
                cnt++;
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}