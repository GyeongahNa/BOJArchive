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
using ll = long long;
using llll = pair<ll, ll>;

#define X first
#define Y second

int M, N, K;
ll mx;
vector<llll> coords, points;

void getInput() {

    cin >> M >> N >> K;
    for (int i=0; i<K; i++) {
        ll y, x;
        cin >> y >> x;
        coords.push_back({N-x, y});
    }

    for (int i=0; i<K; i++) 
        coords.push_back(coords[i]);

    points = {{0, M}, {0, 0}, {N, 0}, {N, M}};
}

ll line(const llll& coord) {

    ll x = coord.X, y = coord.Y;
    if (y == M) return 0;
    if (x == 0) return 1;
    if (y == 0) return 2;
    if (x == N) return 3;
    return -1;
}

int main() {

    // getInput();

    // int nv = 0;
    // for (int i=0; i<K; i++) {
    //     if (line(coords[i]) == -1) continue;
    //     nv++;
    // }

    // if (!nv) {
    //     ll ans = 0;
    //     for (int i=0; i<K; i++)
    //         ans += abs(coords[i].X-coords[i+1].X) + abs(coords[i].Y-coords[i+1].Y);
    //     cout<<1<<" "<<2*(N+M)+ans;
    //     return 0;
    // }

    int cnt = 0;
    int sz = (int)coords.size();

    for (int s=0; s<K; s++) {
        int l = line(coords[s]);
        if (l == -1) continue;
        else if (s+1 >= sz || l == line(coords[s+1])) continue;

        int e;
        for (e = s+1; e<sz && line(coords[e]) == -1; e++) {}

        ll sum = 0;
        for (int i=s+1; i<=e; i++)
            sum += abs(coords[i-1].X-coords[i].X) + abs(coords[i-1].Y-coords[i].Y);

        int lines = line(coords[s]);
        int linee = line(coords[e]);
        int x = coords[s].X, y = coords[s].Y;
        if (linee < lines) linee += 4;

        for (int i=lines; i<=linee; i++) {
            if (i == linee) sum += abs(x-coords[e].X)+abs(y-coords[e].Y);
            else sum += abs(x-points[i%4].X)+abs(y-points[i%4].Y);
            x = points[i%4].X;
            y = points[i%4].Y;
        }

        s = e;
        cnt++;
        mx = max(mx, sum);
    }

    cout<<cnt<<" "<<mx;
    return 0;
}