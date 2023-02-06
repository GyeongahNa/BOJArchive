#include <cstdio>
#include <cstring>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int N, K, x;
vector<int> pos, diff;

int main() {

    cin >> N >> K;
    for (int i=0; i<N; i++) {
        cin >> x;
        pos.push_back(x);
    }
    sort(pos.begin(), pos.end());

    for (int i=0; i<(int)pos.size()-1; i++)
        diff.push_back(pos[i+1]-pos[i]);
    sort(diff.begin(), diff.end());

    int ans = 0;
    for (int i=0; i<N-K; i++) //N-1개 간격 중 K-1개 제거 가능
        ans += diff[i];
    cout << ans;
    return 0;
}