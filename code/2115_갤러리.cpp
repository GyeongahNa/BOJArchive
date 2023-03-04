#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <map>
#include <set>
#include <vector>
#include <stack>
#include <deque>
#include <queue>
#include <climits>
#include <iostream>

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int M, N;
char board[1005][1005];

void getInput() {

    cin >> M >> N;
    for (int i=0; i<M; i++) {
        for (int j=0; j<N; j++)
            cin >> board[i][j];
    }
}

int cntHorz(char up, char down) {

    int ret = 0;
    for (int i=0; i<M-1; i++) {
        //i행, i+1행
        for (int j=0; j<N; j++) {
            if (board[i][j] != up || board[i+1][j] != down) continue;
            int k = j;
            for (;k<N && board[i][k] == up && board[i+1][k] == down; k++) {}
            ret += (k-j)/2;
            j = k-1;
        }
    }

    return ret;
}

int cntVert(char left, char right) {

    int ret = 0;
    for (int i=0; i<N-1; i++) {
        for (int j=0; j<M; j++) {
            if (board[j][i] != left || board[j][i+1] != right) continue;
            int k = j;
            for (;k<M && board[k][i] == left && board[k][i+1] ==right; k++) {}
            ret += (k-j)/2;
            j = k-1; 
        }
    }
    return ret;
 }

int main() {

    getInput();

    cout << cntHorz('X', '.') + cntHorz('.', 'X') + cntVert('X', '.') + cntVert('.', 'X');
    return 0;
}
