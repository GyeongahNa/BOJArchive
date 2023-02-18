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
using iiii = tuple<int, int, int, int>;

#define X first
#define Y second

int N, x, y, z;
int memo[105];
vector<iiii> bricks;
vector<int> record[105];

void getInput() {

    cin >> N;
    for (int i=1; i<=N; i++) {
        cin >> x >> y >> z;
        bricks.push_back({x, y, z, i});
    }

    sort(bricks.begin(), bricks.end());

    for (int i=0; i<105; i++)
        memo[i] = -1;
}

int dfs(int top) {

    if (memo[top] != -1) return memo[top];
    auto [ts, th, tw, tn] = bricks[top];
    if (top == N-1) {
        record[top] = vector<int>(1, tn); 
        return memo[top] = th;
    }

    int re = th;
    vector<int> tmp;
    for (int i=top+1; i<N; i++) {
        auto [s, h, w, n] = bricks[i];
        if (w <= tw) continue;
        int nh = dfs(i)+th;
        if (re < nh) {
            tmp = record[i];
            re = nh;
        }
    }

    tmp.insert(tmp.begin(), tn);
    record[top] = tmp;
    return memo[top] = re;
}

int main() {

    getInput();

    for (int i=0; i<N; i++) dfs(i);

    int re = 0;
    vector<int> tmp;

    for (int i=0; i<N; i++) {
        if (memo[i] > re) {
            tmp = record[i];
            re = memo[i];
        }  
    }

    cout << tmp.size() << '\n';
    for (auto x : tmp) cout << x << "\n";

    return 0;
}