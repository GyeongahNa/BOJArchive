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
using iii = tuple<int, int, int>;

#define X first
#define Y second

int N;
string s;
set<string> prefix;
map<string, int> word;

void nickname(const string& s) {

    string p = "";
    for (int i=0; i<s.size(); i++) {
        p += s[i];
        if (prefix.find(p) != prefix.end()) continue;
        cout << p << '\n';
        return ;
    }

    if (word[s] == 1) cout << s << '\n';
    else cout << (s+to_string(word[s])) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> s;
        word[s] += 1;
        nickname(s);
        string p = "";
        for (int j=0; j<s.size(); j++) {
            p += s[j];
            prefix.insert(p);
        }
    }
    return 0;
}