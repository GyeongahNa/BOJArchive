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

int main() {

    long long N;
    cin >> N;

    long long ans = N;
    ans = min(ans, (N+2)/2);
    ans = min(ans, (N+5)/3);
    ans = min(ans, (N+9)/4);
    ans = min(ans, (N+14)/5);
    ans = min(ans, (N+20)/6);
    ans = min(ans, (N+27)/7);
    cout<<ans;
    return 0;
}