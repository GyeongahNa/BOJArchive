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
using vvi = vector<vector<int>>;
using vvvvi = vector<vector<vvi>>;
using vvc = vector<vector<char>>;
using vvvvc = vector<vector<vvc>>;

#define X first
#define Y second

int stx[4] = {0, 0, 1, 1};
int sty[4] = {0, 1, 0, 1};

int N, mx;
vvvvi igdq(15);
vvvvc igdc(15);

vvi rotate(const vvi& v) {

    int r = (int)v[0].size();
    int c = (int)v.size();

    vvi ret(r, vector<int>(c));
    for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++)
            ret[i][j] = v[c-1-j][i];
    }
    return ret;
}

vvc rotate(const vvc& v) {

    int r = (int)v[0].size();
    int c = (int)v.size();

    vvc ret(r, vector<char>(c));
    for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++)
            ret[i][j] = v[c-1-j][i];
    }
    return ret;
}

void getInput() {

    cin >> N;
    for (int k=0; k<N; k++) {

        vvi q(4, vector<int>(4));
        vvc c(4, vector<char>(4));

        for (int i=0; i<4; i++) {
            for (int j=0; j<4; j++)
                cin >> q[i][j];
        }

        for (int i=0; i<4; i++) {
            for (int j=0; j<4; j++)
                cin >> c[i][j];
        }

        igdq[k].push_back(q);
        igdc[k].push_back(c);

        for (int i=0; i<3; i++) {
            igdq[k].push_back(rotate(igdq[k].back()));
            igdc[k].push_back(rotate(igdc[k].back()));
        }
    }
}

int calc(const vector<int>& selected, int dir, int st) {

    vvi qual(5, vector<int>(5, 0));
    vvc clr(5, vector<char>(5, 'W'));

    for (int i=0; i<3; i++) {
        int d = dir%4;
        int mx = stx[st%4];
        int my = sty[st%4];

        vvi& q = igdq[selected[i]][d];
        vvc& c = igdc[selected[i]][d];

        for (int x=0; x<4; x++) {
            for (int y=0; y<4; y++) {
                qual[x+mx][y+my]+= q[x][y];
                qual[x+mx][y+my] = max(0, qual[x+mx][y+my]);
                qual[x+mx][y+my] = min(9, qual[x+mx][y+my]);
                if (c[x][y] != 'W') clr[x+mx][y+my] = c[x][y];
            }
        }
        dir /= 4;
        st /= 4;
    }

    int r = 0, b = 0, g = 0, y = 0;
    
    for (int i=0; i<5; i++) {
        for (int j=0; j<5; j++) {
            if (clr[i][j] == 'R') r += qual[i][j];
            else if (clr[i][j] == 'B') b += qual[i][j];
            else if (clr[i][j] == 'G') g += qual[i][j];
            else if (clr[i][j] == 'Y') y += qual[i][j];
        }
    }
    return 7*r+5*b+3*g+2*y;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    getInput();

    for (int a=0; a<N; a++) {
        for (int b=0; b<N; b++) {
            for (int c=0; c<N; c++) {
                if (a == b || b == c || a == c) continue; 
                for (int dir=0; dir<(1<<6); dir++) { 
                    for (int st=0; st<(1<<6); st++) 
                        mx = max(mx, calc({a, b, c}, dir, st));
                }
            }
        }
    }

    cout<<mx;
    return 0;
}