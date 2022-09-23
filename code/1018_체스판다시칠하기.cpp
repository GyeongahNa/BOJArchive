#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

int cntDiff(const int& i, const int& j, const vector<vector<char>>& v, char startCol) {

    char col, tmp;
    int cnt;

    col= startCol;
    cnt=0;
    for (int k=i; k<i+8; k++) {
        col=(col=='W' ? 'B' : 'W');
        tmp=col;
        for (int l=j; l<j+8; l++) {
            if (v[k][l] != tmp)
                cnt++;
            tmp=(tmp=='W' ? 'B' : 'W');
        }
    }
    return cnt;
}


int main() {

    int M, N, res, cnt;
    string s;
    
    cin >> M >> N;
    vector<vector<char>> v(M, vector<char>(N));
    for (int i=0; i<M; i++) {
        for (int j=0; j<N; j++)
            cin >> v[i][j];
    }

    res = 64;
    for (int i=0; i<M-8+1; i++) {
        for (int j=0; j<N-8+1; j++) {
            cnt = min(cntDiff(i, j, v, 'W'), cntDiff(i, j, v, 'B'));
            if (res > cnt) res = cnt;
        }
    }
    printf("%d\n", res);
    return 0;
}