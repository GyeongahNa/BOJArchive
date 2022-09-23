#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
using namespace std;

int main() {

    vector<vector<int>>v(100, vector<int>(100));
    int x1, y1, x2, y2, S;

    for (int i = 0; i < 4; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        for (int y = y1; y < y2; y++) {
            for (int x = x1; x < x2; x++) {
                v[y][x] = 1;
            }
        }
    }

    S = 0;
    for (int y = 0; y < 100; y++) {
        for (int x = 0; x < 100; x++) {
            if (v[y][x] == 1)
                S += 1;
        }
    }

    printf("%d\n", S);
    return 0;
}