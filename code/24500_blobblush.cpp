#include <cstdio>
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

long long N;

int main() {

    cin >> N;

    long long x = 1, A = 0;
    while (true) {
        A = (1LL<<x)-1;
        if (A >= N) break;
        x++;
    }

    if (A == N) {
        cout << 1 << '\n' << N;
        return 0;
    }

    cout << 2 << '\n';
    cout << (N^A) << '\n' << N;
}