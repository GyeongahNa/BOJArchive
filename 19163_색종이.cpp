#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
using namespace std;

int main() {

    vector<vector<int>> v(1001, vector<int>(1001));
    int x, y, w, h, N, cnt;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> x >> y >> w >> h;
        for (int j = y; j < y + h; j++) {
            for (int k = x; k < x + w; k++) {
                v[j][k] = i + 1;
            }
        }
    }
    
    for (int i = 0; i < N; i++) {
        cnt = 0;
        for (int j = 0; j < 1001; j++) {
            for (int k = 0; k < 1001; k++) {
                if (v[j][k] == i + 1)
                    cnt++;
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}