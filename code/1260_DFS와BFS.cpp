#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
#include <cmath>
#include <tuple>
#include <queue>
using namespace std;

void dfs(vector<vector<int>> graph, vector<bool>& check, int start) {

    printf("%d ", start);
    check[start] = true;

    for (int i=0; i<graph[start].size(); i++) {
        
        int next = graph[start][i];
        if (check[next]) continue;
        dfs(graph, check, next);
    }
}

void bfs(vector<vector<int>> graph, vector<bool>& check, int start) {

    queue<int> q;
    q.push(start);
    check[start] = true;
    printf("%d ", start);

    while (!q.empty()) {

        int tmp = q.front();

        for (int i=0; i<graph[tmp].size(); i++) {
            int next = graph[tmp][i];
            if (check[next]) continue;
            q.push(next);
            check[next] = true;
            printf("%d ", next);
        }
        q.pop();
    }
}

int main() {

    int N, M, V;
    scanf("%d %d %d", &N, &M, &V);

    vector<vector<int>> graph(N+1, vector<int>(0));
    for (int i=0; i<M; i++) {
        int n1, n2;
        scanf("%d %d", &n1, &n2);

        graph[n1].push_back(n2);
        graph[n2].push_back(n1);
    }

    for (int i=1; i<=N; i++)
        sort(graph[i].begin(), graph[i].end());

    vector<bool> check1(N+1, false), check2(N+1, false);
    dfs(graph, check1, V); 
    printf("\n");
    bfs(graph, check2, V);
    return 0;
}