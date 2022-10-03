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
#include <unordered_map>
#include <unordered_set>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};

int N, M;
int mn = 11;
vector<vector<char>> board(15, vector<char>(15));

void getInput() {

    cin >> N >> M;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++)
            cin >> board[i][j];
    }
}

bool check(int x, int y, const vector<vector<char>>& brd) {
    return brd[x][y] == '.' || brd[x][y] == 'O';
}

int gravitylu(int dir, vector<vector<char>>& brd) {

    bool rch = false, bch = false;

    for (int i=1; i<N-1; i++) {
        for (int j=1; j<M-1; j++) {
            if (brd[i][j] != 'B' && brd[i][j] != 'R') continue;
            int x = i, y = j;
            char ball = brd[i][j];
            while (check(x+dx[dir], y+dy[dir], brd)) {
                x += dx[dir];
                y += dy[dir];
                if (brd[x][y] == 'O') {
                    if (ball == 'R') rch = true;
                    else bch = true;
                    ball = 'O';
                }
            }
            brd[i][j] = '.';
            brd[x][y] = ball;
        }
    }

    if (bch) return 2;
    if (rch) return 1;
    return 0;
}

int gravityrd(int dir, vector<vector<char>>& brd) {

    bool rch = false, bch = false;

    for (int i=N-2; i>=1; i--) {
        for (int j=M-2; j>=1; j--) {
            if (brd[i][j] != 'B' && brd[i][j] != 'R') continue;
            int x = i, y = j;
            char ball = brd[i][j];
            while (check(x+dx[dir], y+dy[dir], brd)) {
                x += dx[dir];
                y += dy[dir];
                if (brd[x][y] == 'O') {
                    if (ball == 'R') rch = true;
                    else bch = true;
                    ball = 'O';
                }
            }
            brd[i][j] = '.';
            brd[x][y] = ball;
        }
    }

    if (bch) return 2;
    if (rch) return 1;
    return 0;
}

int gravity(int dir, vector<vector<char>>& brd) {

    if (dir == 0 || dir == 1) return gravitylu(dir, brd);
    return gravityrd(dir, brd);
}

int main() {

    getInput();
    
    for (int num=0; num<(1<<20); num++) {
        int tmp = num;
        vector<vector<char>> boardcpy = board;
        for (int i=0; i<10; i++) {
            int re = gravity(tmp%4, boardcpy);
            if (re == 2) break;
            if (re == 1) {
                mn = min(mn, i+1);
                break;
            }
            tmp /= 4;
        }
    }

    if (mn == 11) cout<<-1;
    else cout<<mn;
    return 0;
}