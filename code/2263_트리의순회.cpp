#include <cstdio>
#include <cstring>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int n;
int in[100005];
int post[100005];

void pre(int ia, int ib, int pa, int pb) {

    if (ia > ib || pa > pb) return ; 

    cout << post[pb] << " ";
    int idx = find(in+ia, in+ib+1, post[pb])-in;
    pre(ia, idx-1, pa, pa+idx-ia-1);
    pre(idx+1, ib, pa+idx-ia, pb-1);
}

int main() {

    cin >> n;
    for (int i=0; i<n; i++) cin >> in[i];
    for (int i=0; i<n; i++) cin >> post[i];

    pre(0, n-1, 0, n-1);
    return 0;
}