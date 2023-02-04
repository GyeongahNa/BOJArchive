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

int N, M, L, R;
vector<ii> v;
vector<bool> check(10005);

int main() {

    cin >> N >> M;
    for (int i=0; i<M; i++) {
        cin >> L >> R;
        v.push_back({L, R});
    }

    long long re = 1;

    for (int i=(int)v.size()-1; i>=0; i--) {
        bool y = false;
        for (int j=v[i].X; j<=v[i].Y; j++) {
            if (check[j]) continue;
            y = true;
            check[j] = true;
        }
        
        if (y) re *= 2;
    }

    cout << re;
    return 0;
}