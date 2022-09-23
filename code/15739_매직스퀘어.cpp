#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <iostream>

using namespace std;

int main() {

    int N;
    scanf("%d", &N);

    vector<vector<int>> v(N, vector<int>(N));
    vector<int> check(N*N+1, 0);
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            scanf("%d", &v[i][j]);
            check[v[i][j]]++;
        }
    }

    for (int i=1; i<N*N+1; i++) {
        if (check[i] == 1) continue;
        printf("FALSE");
        return 0;
    }

    int sum = 0;
    int num = N*(N*N+1)/2;

    for (int i=0; i<N; i++) {
        sum = 0;
        for (int j=0; j<N; j++)
            sum += v[i][j];
        if (sum != num) {
            printf("FALSE");
            return 0;
        }
    }

    for (int j=0; j<N; j++) {
        sum = 0;
        for (int i=0; i<N; i++) 
            sum += v[i][j];
        if (sum != num) {
            printf("FALSE");
            return 0;
        }
    }

    sum = 0;
    for (int i=0; i<N; i++)
        sum += v[i][i];
    if (sum != num) {
        printf("FALSE");
        return 0;
    }

    sum = 0;
    for (int i=0; i<N; i++)
        sum += v[i][N-1-i];
    if (sum != num) {
        printf("FALSE");
        return 0;
    }

    printf("TRUE");
    return 0;
}