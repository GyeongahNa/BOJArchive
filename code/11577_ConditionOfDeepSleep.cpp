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

int N, K, x;
vector<int> v;
queue<int> q;

void getInput() {

    cin >> N >> K;
    v.push_back(0);

    for (int i=0; i<N; i++) {
        cin >> x;
        v.push_back(x);
    }
}

int flip(int n) {
    return n ? 0 : 1;
}

int getCnt() {

    int cnt = 0;
    for (int i=1; i<=N; i++) {

        while (!q.empty() && q.front() < i) q.pop();

        int status = v[i];
        if (q.size()%2) 
            status = flip(status);
        if (status) {
            int end = i+K-1;
            if (end > N) return -1;
            q.push(i+K-1);
            cnt++;
        }
    }
    return cnt;
}

int main() {

    getInput();

    int re = getCnt();
    if (re == -1) cout << "Insomnia";
    else cout << re;
    return 0;
}