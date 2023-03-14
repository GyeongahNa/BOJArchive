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

int N, M;
int P[15];

void getInput() {

    cin >> N;
    for (int i=0; i<N; i++)
        cin >> P[i];
    cin >> M;
}

int main() {

    getInput();

    int front = min_element(P+1, P+N)-P;
    int mn = min_element(P, P+N)-P;

    if (N <= 1 || P[front] > M) {
        cout << 0;
        return 0;
    }

    int len = (M-P[front])/P[mn]+1;
    vector<int> ret(len);

    for (int i=0; i<len; i++) {
        int j = N-1;
        for (; j>=0; j--) {
            if (M-P[j]-(len-1-i)*P[mn] >= 0) break;
        }
        if (j < 0) break;
        M -= P[j];
        ret[i] = j;
    }

    string ans = "";
    for (int i=0; i<len; i++)
        ans += (ret[i]+'0');
    cout << ans;
    return 0;
}