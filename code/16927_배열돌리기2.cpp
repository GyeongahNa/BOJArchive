#include <cstdio>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int N, M, R;
int board[305][305];

void getInput() {

    cin >> N >> M >> R;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++)
            cin >> board[i][j];
    }
}

void rotate(int x, int y, int n, int m, int r) {

    for (int k=0; k<r; k++) {

        int tmp = board[x][y];
        for (int i=y; i<y+m-1; i++)
            board[x][i] = board[x][i+1];
        for (int i=x; i<x+n-1; i++)
            board[i][y+m-1] = board[i+1][y+m-1];
        for (int i=y+m-1; i>y; i--) 
            board[x+n-1][i] = board[x+n-1][i-1];
        for (int i=x+n-1; i>x; i--)
            board[i][y] = board[i-1][y];
        
        board[x+1][y] = tmp;
    }
}

void printboard() {

    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++)
            cout << board[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

int main() {

    getInput();

    int st = (min(N, M)+1)/2;
    for (int k=0; k<st; k++) {
        int x = k, y = k;
        int n = N-2*k;
        int m = M-2*k;
        int t = n*2+m*2-4;
        int r = R%t;
        rotate(x, y, n, m, r);
    }

    printboard();
}