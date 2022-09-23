#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
#include <cmath>
#include <tuple>
#include <queue>
using namespace std;

int N;
int maxre = -1000000001;
int minre = 1000000001;

void solve(queue<int> q, vector<int> v, int sum) {
    
    if (q.empty()) {
        maxre = max(maxre, sum);
        minre = min(minre, sum);
        return ;
    }

    int front = q.front(); q.pop();

    for (int i=0; i<4; i++) {
        if (v[i] <= 0) continue;
        
        int nextsum = sum;
        if (i == 0) nextsum += front;
        if (i == 1) nextsum -= front;
        if (i == 2) nextsum *= front;
        if (i == 3) nextsum /= front;
        
        v[i]--;
        solve(q, v, nextsum);
        v[i]++;
    }
}

int main() {
    
    scanf("%d", &N);
    
    queue<int> q;
    for (int i=0; i<N; i++) {
        int x;
        scanf("%d", &x);
        q.push(x);
    }
    
    vector<int> v(4, 0);
    for (int i=0; i<4; i++)
        scanf("%d", &v[i]);
    
    int sum = q.front(); q.pop();
    solve(q, v, sum);
    printf("%d\n%d\n", maxre, minre);
    return 0;
}