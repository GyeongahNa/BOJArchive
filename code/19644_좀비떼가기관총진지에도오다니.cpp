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

int L, ML, MK, C;
int Z[3000005], psum[3000005];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> L >> ML >> MK >> C;
    for (int i=1; i<=L; i++) cin >> Z[i];

    for (int i=1; i<=L; i++) {
        int damage = min(i-1, ML-1)*MK;
        damage -= (psum[i-1]-psum[max(i-ML, 0)])*MK;
        if (Z[i]-damage > MK) psum[i] = psum[i-1]+1;
        else psum[i] = psum[i-1];   
    }

    if (psum[L] <= C) cout << "YES";
    else cout << "NO";
    return 0;
}