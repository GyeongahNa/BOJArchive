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
#include <unordered_set>
#include <unordered_map>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

char c[4] = {'L', 'R', 'U', 'D'};
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int T, N, M;
char board[15][15];

void setBoard() {

    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) 
            cin >> board[i][j];
    }
}

bool startFrom(int x, int y, const vector<int>& dirs) {

    for (auto d : dirs) {
        while (board[x+dx[d]][y+dy[d]] == '.') {
            x += dx[d];
            y += dy[d];
        }
        if (board[x+dx[d]][y+dy[d]] == 'O') return true;
    }
    return false;
}

bool checkDirs(const vector<int>& dirs) {

    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            if (board[i][j] != '.') continue;
            if (!startFrom(i, j, dirs)) return false;
        }
    }
    return true;
}

string toString(const vector<int>& dirs) {

    string ret = "";
    for (auto d : dirs) {
        if (d == 0) ret += 'L';
        else if (d == 1) ret += 'R';
        else if (d == 2) ret += 'U';
        else ret += 'D';
    }
    return ret;
}

string getDirs() {

    for (int num=0; num<(1<<20); num++) {
        vector<int> dirs;
        int tmp = num;
        for (int i=0; i<10; i++) {
            dirs.push_back(tmp%4);
            tmp /= 4;
        }
        if (checkDirs(dirs)) 
            return toString(dirs);
    }
    return "XHAE";
}

int main() {

    cin >> T;
    while (T--) {
        cin >> N >> M;
        setBoard();
        cout<<getDirs()<<"\n";
    }
    return 0;
}