#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int N;
vector<long long> v;
int arr[10];

void func(int k) {

    if (k >= 1) {
        long long p = 1, n = 0;
        for (int i=k-1; i>=0; i--) {
            n += arr[i]*p;
            p *= 10;
        }
        v.push_back(n);
        if (k >= 10) return ;
    }

    int st = 9;
    if (k != 0) st = arr[k-1]-1;
    for (int i=st; i>=0; i--) {
        arr[k] = i;
        func(k+1);
    }
}

int main() {
    
    cin >> N;
    func(0);
    sort(v.begin(), v.end());

    if (v.size() < N) cout<<-1;
    else cout<<v[N-1];
    return 0;
}