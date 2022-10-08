#include <cstdio>
#include <cstring>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int d1[2] = {2, 3};
int d2[2] = {1, -1};

int T;
int N, A, B;

bool check[3000005];

void eratos() {

    check[0] = true;
    check[1] = true;

    for (int i=2; i*i<=3000000; i++) {
        if (check[i]) continue;
        for (int j=i*i; j<=3000000; j+=i) 
            check[j] = true;
    }
}

int bfs(int N, int A, int B) {

    queue<int> q;
    q.push(N);

    vector<int> dist(3000005, -1);
    dist[N] = 0;

    while (!q.empty()) {

        int cur = q.front();
        q.pop();

        if (cur >= A && cur <= B && !check[cur]) return dist[cur];

        for (int i=0; i<2; i++) {
            int nx = cur/d1[i];
            if (dist[nx] != -1) continue;
            q.push(nx);
            dist[nx] = dist[cur]+1;
        }

        for (int i=0; i<2; i++) {
            int nx = cur+d2[i];
            if (nx < 0 || nx >= 3000000 || dist[nx] != -1) continue;
            q.push(nx);
            dist[nx] = dist[cur]+1;
        }
    }
    return -1;
}

int main() {

    eratos();

    cin >> T;
    while (T--) {
        cin >> N >> A >> B;
        cout<<bfs(N, A, B)<<endl;
    }
    return 0;
}