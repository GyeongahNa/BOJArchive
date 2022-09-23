#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
#include <cmath>
#include <tuple>
using namespace std;

int w, h;
int map[50][50];
bool visited[50][50];

int dx[] = {-1, 0, 1};
int dy[] = {-1, 0, 1};

void dfs(int x, int y) {

    visited[y][x] = true;

    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {

            if (dx[i] == 0 && dx[j] == 0) continue;
            if (0 > x+dx[i] || x+dx[i] > w-1) continue;
            if (0 > y+dy[j] || y+dy[j] > h-1) continue;
            if (map[y+dy[j]][x+dx[i]] == 0) continue;
            if (visited[y+dy[j]][x+dx[i]]) continue;

            dfs(x+dx[i], y+dy[j]);
        }
    }
}

int main() {

    scanf("%d %d", &w, &h);

    while (w && h) {

        memset(map, 0, sizeof(map));
        memset(visited, false, sizeof(visited));

        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++)
                scanf("%d", &map[y][x]);
        }
        
        int re = 0;
        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
                if (map[y][x] == 0 || visited[y][x]) continue;
                dfs(x, y);
                re++;
            }
        }
        printf("%d\n", re);
        scanf("%d %d", &w, &h);
    }
}