#include <cstdio>
#include <cstring>
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

int N, p, d;
vector<ii> v;
vector<bool> check(10005);

void getInput() {

    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> p >> d;
        v.push_back({d, p});
    }
    sort(v.begin(), v.end());
}

int main() {

    getInput();

    if (!N) {
        cout << 0;
        return 0;
    }

    int sum = 0;
    for (int day=v[N-1].X; day>=1; day--) {
        int mx = 0, mxIdx = -1;
        for (int i=0; i<N; i++) {
            if (check[i]) continue;
            if (day > v[i].X) continue;
            if (mx < v[i].Y) {
                mx = v[i].Y;
                mxIdx = i;
            }
        }
        if (!mx) continue;
        sum += mx;
        check[mxIdx] = true;
    }

    cout << sum;
    return 0;
}