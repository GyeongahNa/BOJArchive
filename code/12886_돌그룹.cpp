#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define first X
#define second Y

int A, B, C, total;
int visited[1500][1500];
queue<ii> q;

int bfs() {

    int mn = min({A, B, C});
    int mx = max({A, B, C});

    q.push({mn, mx});
    visited[mn][mx] = true;

    while (!q.empty()) {

        ii cur = q.front();
        auto [a, b] = cur;
        int c = total-a-b;
        q.pop();

        if (a == b && b == c) return true;

        vector<int> tmp = {a, b, c};
        for (int i=0; i<3; i++) {
            for (int j=i+1; j<3; j++) {
                if (tmp[i] == tmp[j]) continue;
                int na = 0, nb = 0;
                if (tmp[i] < tmp[j]) {
                    na = tmp[i]*2;
                    nb = tmp[j]-tmp[i];
                }
                else {
                    na = tmp[i]-tmp[j];
                    nb = tmp[j]*2;
                }

                int nc = total-na-nb;
                mn = min({na, nb, nc});
                mx = max({na, nb, nc});

                if (visited[mn][mx]) continue;
                q.push({mn, mx});
                visited[mn][mx] = true;
            }
        } 
    }
    return false;
}

int main() {

    cin >> A >> B >> C;
    total = A + B + C;

    if (total%3) {
        cout << 0;
        return 0;
    }
    cout << bfs();
    return 0;
}