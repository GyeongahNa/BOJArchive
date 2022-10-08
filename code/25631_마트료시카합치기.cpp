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
#include <unordered_set>
#include <unordered_map>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int N, x;
vector<int> v;

int main() {

    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> x;
        v.push_back(x);
    }

    int cnt = 0;
    while (v.size()) {

        vector<int> tmp;
        sort(v.begin(), v.end());

        for (int i=0; i<(int)v.size()-1; i++) {
            if (v[i] == v[i+1]) tmp.push_back(v[i]);
        }
        
        v = tmp;
        cnt++;
    }

    cout<<cnt;
    return 0;
}