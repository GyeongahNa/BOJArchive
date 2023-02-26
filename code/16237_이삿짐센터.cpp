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
#include <climits>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int A, B, C, D, E;

void printt() {

    cout << "A : " << A << endl;
    cout << "B : " << B << endl;
    cout << "C : " << C << endl;
    cout << "D : " << D << endl;
    cout << "E : " << E << endl << endl;
}

int main() {

    cin >> A >> B >> C >> D >> E;
    
    int cnt = 0;
    cnt += E;
    
    cnt += D;
    A = max(0, A-D);

    cnt += C;
    int removeB = min(B, C);
    B -= removeB;
    A = max(0, A-(C-removeB)*2);

    cnt += B/2;
    A = max(0, A-B/2);
    if (B%2) {
        ++cnt;
        A = max(0, A-3);
    }

    cnt += A/5;
    if (A%5) ++cnt;
    cout << cnt;
    return 0;
}