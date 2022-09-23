#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
#include <cmath>
#include <tuple>
#include <queue>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

int N, M;
int map[100][100];

void fillMap(int& fsti, int& fstj, int& lasti, int& lastj) {

    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            char c;
            scanf(" %c", &c);
            if (c != '#') continue;

            map[i][j] = 1;
            lasti = i; lastj = j;
            if (fsti != -1 || fstj != -1) continue;
            fsti = i; fstj = j;
        }
    }
}

int main() {

    scanf("%d %d", &N, &M);
    memset(map, 0, sizeof(map));

    int fsti = -1, fstj = -1, lasti = -1, lastj = -1;
    fillMap(fsti, fstj, lasti, lastj);
    
    for (int j = fstj; j <= lastj; j++) {
        if (map[fsti][j] == 1 && map[lasti][j] == 1) continue; 
        if (map[fsti][j] == 0) printf("UP");
        if (map[lasti][j] == 0) printf("DOWN");
    }

    for (int i = fsti; i<=lasti; i++) {
        if (map[i][fstj] == 1 && map[i][lastj] == 1) continue;
        if (map[i][fstj] == 0) printf("LEFT");
        if (map[i][lastj] == 0) printf("RIGHT");
    }
    return 0;
}