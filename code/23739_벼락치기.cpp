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

int N;
int T[105];

int main() {

    cin >> N;
    for (int i=1; i<=N; i++) {
        cin >> T[i];
    }

    int time = 30, cnt = 0;
    for (int i=1; i<=N; i++) {
        if (T[i] <= time*2) ++cnt;
        time = max(0, time-T[i]);
        if (time == 0) time = 30;
    }

    cout << cnt;
    return 0;
}   
