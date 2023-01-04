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
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int>;

#define X first
#define Y second
#define mod 1000000007

string s;
long long v[1000005][3];

int main() {

    cin >> s;

    if (s[0] == 'a') v[0][0] = 1;

    for (int i=1; i<(int)s.size(); i++) {

        v[i][0] = v[i-1][0];
        v[i][1] = v[i-1][1];
        v[i][2] = v[i-1][2];

        if (s[i] == 'a')
            v[i][0] = (v[i-1][0]*2+1)%mod;
        else if (s[i] == 'b')
            v[i][1] = (v[i-1][0] + v[i-1][1]*2)%mod;
        else if (s[i] == 'c')
            v[i][2] = (v[i-1][1] + v[i-1][2]*2)%mod;
    }

    cout << v[(int)s.size()-1][2];
    return 0;
}