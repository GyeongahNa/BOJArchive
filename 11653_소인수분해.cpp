#include <cstring>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <tuple>
#include <stack>
#include <queue>
#include <vector>
#include <iostream>

using namespace std;

int check[10000001];

int main() {
    
    int N;
    scanf("%d", &N);
    memset(check,false, sizeof(check));
    
    queue<int> q;
    for (int i=2; i<= N; i++) {
        if (check[i]) continue;
        q.push(i);
        for (int j=i*2; j<=N; j+=i)
            check[j] = true;
    }
    
    while (!q.empty()) {
        while (N > 0 && !q.empty() && N%q.front() == 0) {
            printf("%d\n",  q.front());
            N/=q.front();
        }
        q.pop();
    }
    
    return 0;
}