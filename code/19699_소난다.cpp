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

int N, M;
vector<int> v;
vector<int> re;
bool dup[10000];
int prime[10000];

void func(int n, int sum, vector<bool> check) {

    if (n == M) {
        if (!prime[sum] && !dup[sum]) {
            re.push_back(sum);
            dup[sum] = true;
        }
        return ;
    }

    for (int i=0; i<check.size(); i++) {
        if (check[i]) continue;
        check[i] = true;
        func(n+1, sum+v[i], check);
        check[i] = false;
    }
}

int main() {

    memset(dup, false, sizeof(dup));
    memset(prime, false, sizeof(prime));

    prime[0] = true;
    prime[1] = true; 
    for (int i=2; i<10000; i++) {
        if (prime[i]) continue;
        for (int j=i*2; j<10000; j+=i) 
            prime[j] = true;
    }

    scanf("%d %d", &N, &M);
    for (int i=0; i<N; i++) {
        int x;
        scanf("%d", &x);
        v.push_back(x);
    }

    vector<bool> check(N);
    func(0, 0, check);

    sort(re.begin(), re.end());
    if (re.size() == 0) printf("-1");
    for (int i=0; i<re.size(); i++)
        printf("%d ", re[i]);
    return 0;
}