#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
#include <cmath>
#include <tuple>
using namespace std;

int dp[71][71][71];

void fillDp() {

    for (int a=-50; a<=20; a++) {
        for (int b=-50; b<=20; b++) {
            for (int c=-50; c<=20; c++) {
                int i = a+50, j = b+50, k = c+50;
                if (a <= 0 || b <= 0 || c <= 0)
                    dp[i][j][k] = 1;
                else if (c > b && b > a)
                    dp[i][j][k] = dp[i][j][k-1]+dp[i][j-1][k-1]-dp[i][j-1][k];
                else
                    dp[i][j][k] = dp[i-1][j][k]+dp[i-1][j-1][k]+dp[i-1][j][k-1]-dp[i-1][j-1][k-1];
            }
        }   
    }
}

int main() {

    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    memset(dp, 0, sizeof(dp));
    fillDp();

    while (a != -1 || b != -1 || c != -1) {

        printf("w(%d, %d, %d) = ", a, b, c);
        if (a <= 0 || b <= 0 || c <= 0) printf("1\n");
        else if (a > 20 || b > 20 || c > 20) printf("%d\n", dp[70][70][70]);
        else printf("%d\n", dp[a+50][b+50][c+50]);
        scanf("%d %d %d", &a, &b, &c);
    }
    return 0;
}