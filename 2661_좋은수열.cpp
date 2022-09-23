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
#include <unordered_set>
#include <unordered_map>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int N;
string s;
bool flag;

bool check(char c) {
    
    string tmp = s+c;
    int sz = tmp.size();
    for (int k=1; k<=sz; k++) {
        if (sz-2*k < 0) continue;
        if (tmp.substr(sz-k, k) == tmp.substr(sz-2*k, k))
            return false;
    }
    return true;
}

void func(int k) {

    if (k >= N) {
        flag = true;
        return ;
    }

    for (int i=1; i<=3; i++) {
        if (!check(i+'0')) continue;
        s += (i+'0');
        func(k+1);
        if (flag) break;
        else s.pop_back();
    }
}

int main() {

    cin >> N;
    func(0);
    cout<<s;
    return 0;
}