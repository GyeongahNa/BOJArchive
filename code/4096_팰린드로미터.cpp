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

bool isPalindrome(string s) {

    int sz = s.size();
    for (int i=0; i<sz/2; i++) {
        if (s[i] != s[sz-1-i]) return false;
    }
    return true;
}

int main() {

    while (true) {
        string s;
        cin >> s;
        if (s == "0") break;

        long long num = stoll(s);
        long long add = 0, sz = s.size();
        while (true) {
            string tmp = to_string(num);
            int fz = max(1LL*0, sz-(int)tmp.size());
            for (int i=0; i<fz; i++) tmp = "0"+tmp;
            if (isPalindrome(tmp)) break;
            add += 1;
            num += 1;
        }
        cout<<add<<'\n';
    }
    return 0;
}