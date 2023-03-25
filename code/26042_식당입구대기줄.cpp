#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iiii = tuple<int, int, int>;

#define X first
#define Y second

int N, cmd, p;
deque<int> dq;
vector<ii> ans;

bool cmp(ii a, ii b) {

    if (a.X > b.X) return true;
    if (a.X < b.X) return false;
    return a.Y < b.Y;
}

int main() {

    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> cmd;
        if (cmd == 1) {
            cin >> p;
            dq.push_back(p);
            ans.push_back({dq.size(), dq.back()});
        }
        else dq.pop_front();
    }

    sort(ans.begin(), ans.end(), cmp);
    cout << ans[0].X << " " << ans[0].Y;
    return 0;
}