#include <cstdio>
#include <cstring>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <map>
#include <list>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

string s, t;
int cnt[26];

int main() {

    cin >> s >> t;
    for (auto& c : s) {
        for (int i=0; i<t.size(); i++) {
            if (t[i] != c) continue;
            if (i == 0 || cnt[i] < cnt[i-1]) cnt[i]++;
            break;
        }
    }

    cout << cnt[t.size()-1];
    return 0;
}