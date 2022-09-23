#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
#include <cmath>
#include <tuple>
using namespace std;

vector<vector<int>> vGraph(101);
vector<bool> vCheck(101);

void dfs(int start, int end, int depth, int& re) {

    if (start == end) re = depth;

    vCheck[start] = true;
    depth++;
    for (int i=0; i<vGraph[start].size(); i++) {
        int next = vGraph[start][i];
        if (!vCheck[next]) dfs(next, end, depth, re);
    }
}

int main() {

    int n, s, e, m;
    scanf("%d %d %d %d", &n, &s, &e, &m);

    for (int i=0; i<m; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        vGraph[x].push_back(y);
        vGraph[y].push_back(x);
    }

    int depth = 0, re = -1;
    dfs(s, e, depth, re);
    printf("%d", re);
    return 0;
}
