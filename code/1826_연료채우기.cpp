#include <cstdio>
#include <cstring>
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

int N, a, b, L, P;
vector<ii> v;
priority_queue<int, vector<int>, less<int>> pq;

void getInput() {

    cin >> N;
    for (int i=1; i<=N; i++) {
        cin >> a >> b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end());

    cin >> L >> P;
}

int main() {

    getInput();

    int mx = P, idx = 0, cnt = 0;
    while (mx < L) {

        while (idx < N && v[idx].X <= mx) {
            pq.push(v[idx].Y);
            idx++;
        }

        if (pq.empty()) {
            cout << -1;
            return 0;
        }
        
        mx += pq.top();
        pq.pop();
        ++cnt;
    }

    cout << cnt;
    return 0;  
}