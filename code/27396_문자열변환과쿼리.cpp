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

string s;
char x, y;
int n, cmd;
map<char, char> m;

int main() {

    cin >> s >> n;
    for (char a='A'; a<='Z'; a++) {
        m[a] = a;
        m[a+32] = a+32;
    }

    for (int i=0; i<n; i++) {
        cin >> cmd;
        if (cmd == 1) {
            cin >> x >> y;
            for (auto [a, b] : m) {
                if (b == x) m[a] = y;
            }
            continue;
        }

        for (auto x : s) {
            cout << m[x];
        }
        cout << '\n';
    }

    return 0;
}