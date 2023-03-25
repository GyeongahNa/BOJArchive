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

int x, y;

string convert(int a) {

    string ret = "";
    
    while (a) {
        ret = string(1, a%3+'0') + ret;
        a /= 3;
    }

    return ret;
}

string zero(int n) {
    
    string ret = "";
    for (int i=0; i<n; i++) ret += "0";
    return ret;
}

int main() {

    cin >> x >> y;

    string s1 = convert(x);
    string s2 = convert(y);

    int len = max(s1.size(), s2.size());
    s1 = zero(len-s1.size())+s1;
    s2 = zero(len-s2.size())+s2;

    int ans = 1;
    for (int i=0; i<len; i++) {
        if (s1[i] == '1' && s2[i] == '0') continue;
        if (s1[i] == '0' && s2[i] == '1') continue;
        ans = 0;
    }

    cout << ans;
    return 0;
}