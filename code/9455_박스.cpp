#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
using namespace std;

int main() {

    int T, M, N, numBag, cnt;
    vector<int> vRes;

    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> M >> N;
        vector<vector<int>> v(M, vector<int>(N));
        for (int m = 0; m < M; m++) {
            for (int n = 0; n < N; n++)
                cin >> v[m][n];
        }

        cnt = 0;
        for (int n = 0; n < N; n++) {
            numBag  = 0;
            for (int m = 0; m < M; m++) {
                if (v[m][n] == 1) {
                    numBag++;
                    cnt += M - m - 1;
                }
            }
            for (int b = 1; b < numBag; b++) 
                cnt -= b;
        }
        vRes.push_back(cnt);
    }

    for (int i = 0; i < vRes.size(); i++)
        printf("%d\n", vRes[i]);
    return 0;
}