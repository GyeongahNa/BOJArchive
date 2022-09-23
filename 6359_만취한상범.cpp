#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
using namespace std;


int getOpenNum(int N) {
    
    int cnt, sum;

    sum = 0;
    for (int i = 1; i <= N; i++) {
        // 약수의 개수
        cnt = 0;
        for (int j = 1; j <= i; j++) {
            if (i % j == 0)
                cnt++;
        }
        if (cnt % 2 == 1)
            sum += 1;
    }
    return sum;
}

int main() {
    
    int T, N;
    int *res;

    cin >> T;
    res = new int[T];

    for (int i = 0; i < T; i++) {
        cin >> N;
        res[i] = getOpenNum(N);
    }

    for (int i = 0; i < T; i++) 
        printf("%d\n", res[i]);
    return 0;
}

// 이거 gglifer 이분 코드 보니까 그냥 (int)sqrt(N)하면 끝나는 문제