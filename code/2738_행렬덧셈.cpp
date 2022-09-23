#include <cstring>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <iostream>

using namespace std;

int main() {

    int N, M;
    scanf("%d %d", &N, &M);

    vector<vector<int>> v(N, vector<int>(M));
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++)
            scanf("%d", &v[i][j]);
    }

    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            int x;
            scanf("%d", &x);
            printf("%d ", v[i][j]+x);
        }
        printf("\n");
    }
    return 0;
}