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

int N;
ii island[1005];

void getInput() {

    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> island[i].X >> island[i].Y;
    }
}

int main() {

    getInput();

    double xx = 0, yy = 0;
    for (int i=0; i<N; i++) {
        xx += island[i].X;
        yy += island[i].Y;
    }

    xx /= N;
    yy /= N;

    double rat = 0.1, mx;
    for (int i=0; i<50000; i++) {
        mx = -1;
        int mxIdx = -1;
        for (int j=0; j<N; j++) {
            double dist = (xx-island[j].X)*(xx-island[j].X)+(yy-island[j].Y)*(yy-island[j].Y);
            if (dist > mx) {
                mxIdx = j;
                mx = dist;
            }
        }

        xx += (island[mxIdx].X-xx)*rat;
        yy += (island[mxIdx].Y-yy)*rat;
        rat *= 0.998;
    }

    printf("%.3f %.3f\n", xx, yy);
    printf("%.3f", sqrt(mx));
}