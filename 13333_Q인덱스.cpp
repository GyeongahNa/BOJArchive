#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int N;
vector<int> v;

int main() {

    cin >> N;
    v.resize(N);
    for (int i=0; i<N; i++) cin >> v[i];
    sort(v.begin(), v.end());

    for (int i=0; i<N; i++) {
        int k = N-i;
        if (v[i] >= k && i == N-k) {
            cout<<k;
            return 0;
        }
    }
    cout<<0;
    return 0;
}