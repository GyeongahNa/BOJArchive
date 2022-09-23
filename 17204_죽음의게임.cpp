#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <iostream>

using namespace std;

int N, K;
vector<int> v;
vector<bool> check(150, false);
int re;

void dfs(int node, int cnt) {

    check[node] = true;
    if (node == K) {
        re = cnt;
        return ;
    }
    if (check[v[node]]) {
        re = -1;
        return ;
    }
    dfs(v[node], cnt+1);
}

int main() {
    
    scanf("%d %d", &N, &K);

    for (int i=0; i<N; i++) {
        int x;
        scanf("%d", &x);
        v.push_back(x);
    }

    dfs(0, 0);
    printf("%d", re);
    return 0;
}