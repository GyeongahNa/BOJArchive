#include <cstdio>
#include <cstring>
#include <cmath>
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
#define inf 1e9

struct Line {

    int x1, y1, x2, y2;
    int dir;

    Line(int x1_, int y1_, int x2_, int y2_) : x1(x1_), y1(y1_), x2(x2_), y2(y2_) {
        if (x1 == x2) dir = 0;
        else dir = 1;
        if (y1 > y2) swap(y1, y2);
        if (x1 > x2) swap(x1, x2);
    }
};

int L, N;
vector<ii> input;
vector<Line> lines;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void setInput() {

    cin >> L >> N;
    while (N--) {
        int t;
        char d;
        cin >> t >> d;
        if (d == 'L') input.push_back({t, 0});
        else input.push_back({t, 1});
    }

    //마지막 이동은 방향 전환 없이 직진
    input.push_back({inf, 0});
}

int rotate(int dir, int next) {

    if (!next) return (dir+3)%4;
    return (dir+1)%4;
}

long long getDieTime() {

    lines.push_back(Line(-L-1, -L-1, -L-1, L+1));
    lines.push_back(Line(-L-1, -L-1, L+1, -L-1));
    lines.push_back(Line(L+1, -L-1, L+1, L+1));
    lines.push_back(Line(-L-1, L+1, L+1, L+1));
    
    int x = 0, y = 0, d = 0;
    long long ans = 0;
    
    for (auto [ot, nd] : input) {
        
        //충돌하기까지의 거리 구하기
        int t = inf;
        for (auto line : lines) {
            if (line.dir == 0) {
                if (d == 0) {
                    if (x == line.x1 && y < line.y1)
                        t = min(t, line.y1-y);
                }
                else if (d == 1) {
                    if (x < line.x1 && line.y1 <= y && y <= line.y2)
                        t = min(t, line.x1-x);
                }
                else if (d == 2) {
                    if (x == line.x1 && y > line.y2)
                        t = min(t, y-line.y2);
                }
                else {
                    if (x > line.x1 && line.y1 <= y && y <= line.y2) {
                    
                        t = min(t, x-line.x1);
                }
                }
            }
            else {
                if (d == 0) {
                    if (y < line.y1 && line.x1 <= x && x <= line.x2)
                        t = min(t, line.y1-y);
                }
                else if (d == 1) {
                    if (y == line.y1 && x < line.x1) 
                        t = min(t, line.x1-x);
                }
                else if (d == 2) {
                    if (y > line.y1 && line.x1 <= x && x <= line.x2)
                        t = min(t, y-line.y1);
                }
                else {
                    if (x > line.x2 && line.y1 == y) 
                        t = min(t, x-line.x2);
                }
            }
        }

        if (t <= ot) return ans+t;
        ans += ot;
        int nx = x+dx[d]*ot;
        int ny = y+dy[d]*ot;
        d = rotate(d, nd);
        lines.push_back(Line(x, y, nx, ny));
        x = nx;
        y = ny;
    }
    return ans;
}

int main() {

    setInput();
    cout<<getDieTime();
    return 0;
}