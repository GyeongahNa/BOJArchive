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
using iii = tuple<int, int, int>;

int N, M;
bool check[1001];
vector<int> graph[1001];

int getStart() {
    
    for (int i=1; i<=N; i++)
        if (!check[i]) return i;
    return 0;
}

void bfs(int s) {

    queue<int> q;
    q.push(s);
    check[s] = true;

    while (q.size()) {

        int qs = q.size();
        while (qs--) {

            int front = q.front();
            q.pop();
            for (int i=0; i<graph[front].size(); i++) {
                int next = graph[front][i];
                if (check[next]) continue ;
                q.push(next);
                check[next] = true;
            }
        }
    }
}

int main() {

    scanf("%d %d", &N, &M);
    memset(check, false, sizeof(check));

    for (int i=0; i<M; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int s, cnt = 0;
    while ((s = getStart())) {
        bfs(s);
        cnt++;
    }
    printf("%d", cnt);
    return 0;
}