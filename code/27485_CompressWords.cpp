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

int N;
vector<string> v;

int main() {

    cin >> N;
    for (int i=0; i<N; i++) {
        string s;
        cin >> s;
        v.push_back(s);
    }

    string ret = v[0];
    for (int i=1; i<N; i++) {
        string add = v[i];
        int rsz = ret.size();
        int vsz = v[i].size();
        for (int j=0; j<rsz; j++) {
            if (ret.substr(j, rsz-j) == v[i].substr(0, rsz-j)) {
                add = v[i].substr(rsz-j);
                break;
            }
        }
        ret += add;
    }
    cout << ret;
    return 0;
}