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
#include <climits>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int a1, a0, c, n0;

int main() {

    cin >> a1 >> a0 >> c >> n0;

    if (a1-c > 0) {
        cout << 0;
        return 0;
    }

    if ((a1-c)*n0 <= -a0) cout << 1;
    else cout << 0;
    return 0;
}