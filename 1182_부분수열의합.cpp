#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
#include <cmath>
#include <tuple>
using namespace std;

void cntEqualSum(const vector<int>& v, int idx, int total, int sum, int& cnt) {

    if (idx == v.size()) {
        if (total == sum) cnt++;
        return ;
    }
    
    cntEqualSum(v, idx+1, total, sum, cnt);
    cntEqualSum(v, idx+1, total+v[idx], sum, cnt);
}

int main() {

    int N, S;
    scanf("%d %d", &N, &S);

    vector<int> v(N);
    for (int i=0; i<N; i++)
        scanf("%d", &v[i]);

    int cnt = 0;
    cntEqualSum(v, 0, 0, S, cnt);

    if (S == 0) cnt--;
    printf("%d", cnt);
    return 0;
}