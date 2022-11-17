#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <climits>
#include <cctype>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int T, N, M, x;

int main() {

    cin >> T;
    while (T--) {

        cin >> N >> M;
        vector<int> cnt(N+1, 0);
        for (int i=0; i<M; i++) {
            for (int j=1; j<=N; j++) {
                cin >> x;
                cnt[j] += x;
            }
        }
        cout<<max_element(cnt.begin(), cnt.end())-cnt.begin()<<'\n';
    }
    return 0;
}