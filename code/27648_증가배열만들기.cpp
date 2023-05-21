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
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

int N, M, K;

int main() {

    cin >> N >> M >> K;
    if (N+(M-1) > K) {
        cout << "NO";
        return 0;
    }

    cout << "YES" << '\n';
    for (int i=1; i<=N; i++) {
        for (int j=0; j<M; j++) {
            cout << i+j<<" ";  
        }
        cout << '\n';
    }
    return 0;
}