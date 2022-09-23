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

bool check[10000];

int main() {
    
    memset(check, false, sizeof(check));
    
    int n;
    scanf("%d", &n);
    
    int cnt = 0;
    while (!check[n]) {
        cnt++;
        check[n] = true;
        n = (n-n/1000*1000)/10;
        n = n*n;
    }
    printf("%d", cnt);
    return 0;
}