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

int A, a, B, b, P;

int main() {

    cin >> A >> a >> B >> b >> P;

    if (P >= B && b >= A) cout << "Yes" << endl;
    else if (P >= A && a >= B) cout << "Yes" << endl;
    else if (A+B <= P) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}