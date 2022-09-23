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

int N, r, c, idx = 0;

void solve(int x, int y, int size) {

    if (x == c && y == r) {
        printf("%d", idx);
        return ;
    }

    if (c >= x && x+size > c && r >= y && y+size > r) {
        solve(x, y, size/2);
        solve(x+size/2, y, size/2);
        solve(x, y+size/2, size/2);
        solve(x+size/2, y+size/2, size/2);
    }
    else idx+=size*size;
}

int main() {

    scanf("%d %d %d", &N, &r, &c);
    solve(0, 0, 1<<N); // 1<<N: 2^N
    return 0;
}