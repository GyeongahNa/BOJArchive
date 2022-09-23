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

#define xx first
#define yy second

int l;
int map[300][300];
bool visited[300][300];

int dx[] = {-1, 1, -2, 2, -2, 2, -1, 1};
int dy[] = {-2, -2, -1, -1, 1, 1, 2, 2};

int bfs(int x, int y, int endx, int endy) {

    queue<ii> q;
    q.push({x, y});
    q.push({-1, -1});
    visited[y][x] = true;

    int depth = 0;
    while (!q.empty()) {
        
        ii pos = q.front();
        x = pos.xx; y = pos.yy;

        if (x == endx && y == endy) return depth;
        else if (x == -1 && y == -1) {
            depth++;
            q.pop();
            q.push({-1, -1});
        }
        else {
            for (int i = 0; i < 8; i++) {
                if (0 > y+dy[i] || y+dy[i] > l-1) continue;
                if (0 > x+dx[i] || x+dx[i] > l-1) continue;
                if (visited[y+dy[i]][x+dx[i]]) continue; 

                q.push({x+dx[i], y+dy[i]});
                visited[y+dy[i]][x+dx[i]] = true;
            }
            q.pop();
        }
    }
    return -1;
}

int main() {

    int T;
    scanf("%d", &T);

    for (int t = 0; t < T; t++) {

        int sx, sy, ex, ey;
        scanf("%d %d %d %d %d", &l, &sx, &sy, &ex, &ey);

        memset(map, 0, sizeof(map));
        memset(visited, false, sizeof(visited));
        printf("%d\n", bfs(sx, sy, ex, ey));
    }
    return 0;
}