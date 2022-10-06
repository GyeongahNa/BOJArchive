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

ll M, N, K;
vector<ii> coords, points;

void getInput() {

    cin >> M >> N >> K;
    for (int i=0; i<K; i++) {
        int y, x;
        cin >> y >> x;
        coords.push_back({N-x, y});
    }

    for (int i=0; i<K; i++)
        coords.push_back(coords[i]);

    points = {{0, 0}, {N, 0}, {N, M}, {0, M}};
}

vector<int> line(const ii& coord) {

    vector<int> ret;
    int x = coord.X, y = coord.Y;

    if (x == 0) ret.push_back(0);
    if (y == 0) ret.push_back(1);
    if (x == N) ret.push_back(2);
    if (y == M) ret.push_back(3);
    return ret;
}

bool noLine() {

    int nv = 0;
    for (int i=0; i<K; i++) {
        if (line(coords[i]).size()) nv++;
    }
    return nv == 0;
}

bool sameLine(const ii& coord1, const ii& coord2) {

    vector<int> l1 = line(coord1);
    vector<int> l2 = line(coord2);

    for (auto x : l1) {
        for (auto y: l2) {
            if (x == y) return true;
        }
    }
    return false;
}

int main() {

    getInput();

    //모든 점이 내부에 있을 때 
    if (noLine()) {
        ll ans = 0;
        for (int i=0; i<K; i++) 
            ans += abs(coords[i].X-coords[i+1].X)+abs(coords[i].Y-coords[i+1].Y);
        cout<<1<<" "<<2*(N+M)+ans;
        return 0;
    }

    ll cnt = 0, mx = 0;
    int sz = (int)coords.size();

    for (int s=0; s<K; s++) {
        vector<int> l = line(coords[s]);
        if (!l.size()) continue;

        int e;
        for (e = s+1; e<sz && !line(coords[e]).size(); e++) {}
        if (s+1 == e && sameLine(coords[s], coords[e])) continue;

        //조각의 내부 테두리 합
        ll sum = 0;
        for (int i=s+1; i<=e; i++) 
            sum += abs(coords[i].X-coords[i-1].X)+ abs(coords[i].Y-coords[i-1].Y);

        int lines = line(coords[s])[0];
        int linee = line(coords[e])[0];
        int x = coords[s].X, y = coords[s].Y;

        //조각의 외부 테두리 합
        for (int i=lines; i<lines+4; i++) {
            int d = i%4;
            if (d != linee) {
                sum += abs(x-points[d].X)+abs(y-points[d].Y);
                x = points[d].X;
                y = points[d].Y;
                continue;
            }
            sum += abs(x-coords[e].X)+abs(y-coords[e].Y);
            break;
        }

        s = e;
        cnt++;
        mx = max(mx, sum);
    }

    cout<<cnt<<" "<<mx;
    return 0;
}