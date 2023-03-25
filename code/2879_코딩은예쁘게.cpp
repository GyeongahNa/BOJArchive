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

int N, x;
vector<int> cur, fut, diff;

void getInput() {

    cin >> N;
    
    for (int i=0; i<N; i++) {
        cin >> x;
        cur.push_back(x);
    }

    for (int i=0; i<N; i++) {
        cin >> x;
        fut.push_back(x);
    }

    for (int i=0; i<N; i++) {
        diff.push_back(fut[i]-cur[i]);
    }
}

int sign(int a) {
    
    if (!a) return 0;
    if (a < 0) return -1;
    return 1;
}

int main() {

    getInput();

    int sum = 0;
    for (int i=0; i<N; i++) {
        if (!diff[i]) continue;
        if (i < N-1 && sign(diff[i]) == sign(diff[i+1])) {
            if (abs(diff[i]) > abs(diff[i+1]))
                sum += abs(diff[i])-abs(diff[i+1]);
        }
        else sum += abs(diff[i]);
    }

    cout << sum;
    return 0;
}