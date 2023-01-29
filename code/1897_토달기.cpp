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

int d, mx;
string s, tmp, ans;
map<string, int> m;

void getInput() {

    cin >> d >> s;
    for (int i=0; i<d; i++) {
        cin >> tmp;
        m[tmp] = 0;
    }
}

void bfs() {

    queue<string> q;
    q.push(s);
    m[s] = 1;

    while (!q.empty()) {

        string cur = q.front();
        q.pop();

        int sz = cur.size();
        if (mx <= sz) {
            ans = cur;
            mx = sz;
        }

        for (int i=0; i<=sz; i++) {
            for (int j=0; j<=25; j++) {
                string nstr = cur;
                nstr.insert(nstr.begin()+i, 'a'+j);
                if (m.find(nstr) == m.end()) continue;
                if (m[nstr] == 1) continue;
                m[nstr] = 1;
                q.push(nstr);
            }
        }
    }
}

int main() {

    getInput();
    bfs();
    cout << ans;
    return 0;
}