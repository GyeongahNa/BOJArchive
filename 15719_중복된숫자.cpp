#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<bool> check(N, 0);
    while (N--) {
        int x;
        cin >> x;
        if (check[x]) {
            cout << x;
            break;
        }
        check[x] = true;
    }
    return 0;
}