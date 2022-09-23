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

int N;
bool check[100001];
vector<int> graph[100001];
vector<ii> re;

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
                if (check[next]) continue;
                q.push(next);
                check[next] = true;
                re.push_back({next, front});
            }
        }
    }
}

int main() {

    scanf("%d", &N);
    memset(check, false, sizeof(check));
    for (int i=1; i<=N-1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    bfs(1);
    sort(re.begin(), re.end());
    for (int i=0; i<re.size(); i++)
        printf("%d\n", re[i].second);
    return 0;
}