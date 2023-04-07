#include <cstdio>
#include <cstring>
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

#define X first
#define Y second

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int N, K, x;
vector<vector<ii>> board(10, vector<ii>(10));
vector<int> bullet(10);

void getInput() {

    cin >> N >> K;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cin >> x;
            board[i][j].X = x;
            board[i][j].Y = x;
        }
    }

    for (int i=0; i<K; i++) {
        cin >> bullet[i];
    }
}

void shoot(vector<vector<ii>>& status, int r, int attack, int& score, int num) {

    int c = 0;
    while (c < N && !status[r][c].X) c++;
    if (c >= N) return ;
    
    if (status[r][c].X >= 10) {
        score += status[r][c].X;
        status[r][c].X = 0;
        status[r][c].Y = 0;
        return ;
    }

    status[r][c].Y -= attack;
    if (status[r][c].Y <= 0) {
        for (int i=0; i<4; i++) {
            int nx = r+dx[i];
            int ny = c+dy[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            if (status[nx][ny].X) continue;
            status[nx][ny].X = status[r][c].X/4;
            status[nx][ny].Y = status[r][c].X/4;
        }
        score += status[r][c].X;
        status[r][c].X = 0;
        status[r][c].X = 0;
    }
}

int main() {

    getInput();

    int tot = 1;
    for (int i=0; i<K; i++) tot *= N;

    int mx = 0;
    for (int num=0; num<tot; num++) {
        int tmp = num, score = 0;
        vector<vector<ii>> status = board;
        for (int i=0; i<K; i++) {
            shoot(status, tmp%N, bullet[i], score, num);
            tmp /= N;
        }
        mx = max(mx, score);
    }
    cout << mx;
    return 0;
}