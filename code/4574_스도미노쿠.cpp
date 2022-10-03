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

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int N;
bool flag;
vector<vector<int>> board(15, vector<int>(15, 0)); 
vector<ii> dominos;

void getInput() {

    flag = false;
    for (int i=0; i<15; i++) {
        for (int j=0; j<15; j++)
            board[i][j] = 0;
    }

    dominos.clear();
    for (int i=1; i<=8; i++) {
        for (int j=i+1; j<=9; j++)
            dominos.push_back({i, j});
    }

    for (int i=0; i<N; i++) {
        int U, V;
        string LU, LV;
        cin >> U >> LU >> V >> LV;
        dominos.erase(find(dominos.begin(), dominos.end(), ii({min(U, V), max(U, V)})));
        board[LU[0]-'A'+1][LU[1]-'0'] = U;
        board[LV[0]-'A'+1][LV[1]-'0'] = V;
    }

    for (int i=1; i<=9; i++) {
        string P;
        cin >> P;
        board[P[0]-'A'+1][P[1]-'0'] = i;
    }
}

bool check(int x, int y, int num) {

    for (int i=1; i<=9; i++) {
        if (board[x][i] == num) return false;
        if (board[i][y] == num) return false;
    }

    int stx = (x-1)/3*3+1;
    int sty = (y-1)/3*3+1;

    for (int i=stx; i<stx+3; i++) {
        for (int j=sty; j<sty+3; j++) {
            if (board[i][j] == num) return false;
        }
    }
    return true;
}

void printboard(int cnt) {

    cout<<"Puzzle "<<cnt<<endl;
    for (int i=1; i<=9; i++) {
        for (int j=1; j<=9; j++)
            cout<<board[i][j];
        cout<<'\n';
    }
}

void solve(int k, int cnt) {

    if (flag) return ;
    if (k == (int)dominos.size()) {
        flag = true;
        printboard(cnt);
        return ;
    }

    for (int x=1; x<=9; x++) {
        for (int y=1; y<=9; y++) {
            if (board[x][y]) continue;
            if (!check(x, y, dominos[k].X)) continue;
            for (int i=0; i<4; i++) {
                int nx = x+dx[i];
                int ny = y+dy[i];
                if (nx < 1 || nx > 9 || ny < 1 || ny > 9) continue;
                if (board[nx][ny]) continue;
                if (!check(nx, ny, dominos[k].Y)) continue;
                board[x][y] = dominos[k].X;
                board[nx][ny] = dominos[k].Y;
                solve(k+1, cnt);
                board[x][y] = 0;
                board[nx][ny] = 0;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int cnt = 0;
    while (true) {
        cin >> N;
        if (N == 0) return 0;
        getInput();
        solve(0, ++cnt);
    }
    return 0;
}