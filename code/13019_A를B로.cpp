#include <cstdio>
#include <cstring>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

string A, B, C, D;

int main() {

    cin >> A >> B;
    C = A, D = B;

    sort(C.begin(), C.end());
    sort(D.begin(), D.end());

    if (C != D) {
        cout << -1;
        return 0;
    }

    int cnt = 0;
    int j = B.size()-1;
    for (int i=A.size()-1; i>=0; i--) {
        if (A[i] == B[j]) j--;
        else cnt++;
    }

    cout << cnt;
    return 0;
}