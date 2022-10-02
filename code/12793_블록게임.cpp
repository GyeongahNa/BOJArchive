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

int N, M;
double K;
char input[250][250];
int board[250][250];

int dx[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[8] = {0, 0, -1, 1, -1, 1, -1, 1};

bool OOB(int x, int y) {
    return x < 0 || x >= 2*M+1 || y < 0 || y >= 2*N+1;
}

void bfs(int x, int y, int nB) {

    queue<ii> q;
    q.push({x, y});
    board[x][y] = nB;

    while (!q.empty()) {
        ii cur = q.front();
        q.pop();

        for (int i=0; i<4; i++) {
            int nx = cur.X+dx[i];
            int ny = cur.Y+dy[i];

            if (OOB(nx, ny)) continue;
            if (input[nx][ny] != '.' && input[nx][ny] != 'B') continue;
            if (board[nx][ny]) continue;
            q.push({nx, ny});
            board[nx][ny] = nB;
        }
    }
}

void getInput() {

    //입력 받기
    cin >> N >> M >> K;
    for (int i=0; i<2*M+1; i++) {
        for (int j=0; j<2*N+1; j++)
            cin >> input[i][j];
    }

    //블록 번호 지정
    int nB = 1;
    for (int i=0; i<2*M+1; i++) {
        for (int j=0; j<2*N+1; j++) {
            if (input[i][j] != 'B' || board[i][j]) continue;
            bfs(i, j, nB++);
        }
    }
}

void changeDir(int& x, int& y, int& d) {

    if (y <= 0) {
        if (d == 6) d = 7;
        else if (d == 4) d = 5;
    }
    else if (x <= 0) {
        if (d == 5) d = 7;
        else if (d == 4) d = 6;
    }
    else if (y >= 2*N) {
        if (d == 7) d = 6;
        else if (d == 5) d = 4;
    }
}

int main() {

    getInput();

    //시작 상태
    int x = 2*M;
    int y = 2*K;
    int d = 4;
    set<int> st;

    //이동, 회전
    while (true) {
        if (board[x][y] >= 1) st.insert(board[x][y]);
        else if (input[x][y] == '-') { //가로선은 상하 확인
            if (board[x-1][y] >= 1) st.insert(board[x-1][y]);
            if (board[x+1][y] >= 1) st.insert(board[x+1][y]);
        }
        else if (input[x][y] == '|') { //세로선을 지날 때는 좌우 확인
            if (board[x][y-1] >= 1) st.insert(board[x][y-1]);
            if (board[x][y+1] >= 1) st.insert(board[x][y+1]);
        }

        x += dx[d];
        y += dy[d];
        if (x >= 2*M) break; 
        changeDir(x, y, d);
    }

    cout<<(int)st.size();
    return 0;
}