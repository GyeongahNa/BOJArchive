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

int T, Q, K, N;
string cmd;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> T;
    while (T--) {
        
        cin >> Q >> K;
        int re = 0;
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int i=0; i<Q; i++) {
            cin >> cmd;
            if (cmd == "insert") {
                cin >> N;
                if (pq.size() < K) {
                    re ^= N;
                    pq.push(N);
                }
                else {
                    int mn = pq.top();
                    if (mn < N) {
                        pq.pop();
                        pq.push(N);
                        re ^= mn;
                        re ^= N;
                    }
                }
            }
            else cout<<re<<'\n'; //print
        }
    }
    return 0;
}