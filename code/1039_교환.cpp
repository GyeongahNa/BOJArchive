#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int N, K, mx;
bool visited[1000005][15];

void bfs() {

    queue<ii> q;
    q.push({N, 0});
    visited[N][0] = true;

    while (!q.empty()) {

        ii cur = q.front();        
        q.pop();

        if (cur.Y >= K) {
            mx = max(cur.X, mx);
            continue;
        }

        string s = to_string(cur.X);
        int sz = s.size();

        for (int i=0; i<sz-1; i++) {
            for (int j=i+1; j<sz; j++) {
                string tmp = s;
                swap(tmp[i], tmp[j]);
                if (tmp[0] == '0') continue;
                int num = stoi(tmp);
                if (visited[num][cur.Y+1]) continue;
                q.push({num, cur.Y+1});
                visited[num][cur.Y+1] = true;
            }
        }
    }
}

int main() {

    cin >> N >> K;
    bfs();
    if (!mx) cout << -1;
    else cout << mx;
    return 0;
}