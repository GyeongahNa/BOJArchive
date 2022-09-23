#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
#include <cmath>
#include <tuple>
#include <queue>
using namespace std;

int N;
vector<vector<int>> graph(100);

void dfs(int node, vector<int>& check) {
    
    for (int i=0; i<graph[node].size(); i++) {
        int next = graph[node][i];
        if (check[next] == 1) continue;
        check[next] = 1;
        dfs(next, check);
    }
}

int main() {
    
    scanf("%d", &N);
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            int x;
            scanf("%d", &x);
            if (x == 0) continue;
            graph[i].push_back(j);
        }
    }

    for (int i=0; i<N; i++) {
        vector<int> check(N, 0);
        dfs(i, check);
        for (int j=0; j<N; j++) 
            printf("%d ", check[j]);
        printf("\n");
    }
    
    return 0;
}