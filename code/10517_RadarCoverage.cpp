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
using dd = pair<double, double>;

#define X first
#define Y second

int T;
dd coords[3];

int main() {

    cin >> T;
    for (int t=1; t<=T; t++) {
        
        double xx = 0, yy = 0;
        for (int i=0; i<3; i++) {
            cin >> coords[i].X >> coords[i].Y;
            xx += coords[i].X;
            yy += coords[i].Y;
        }

        xx /= 3;
        yy /= 3;

        double rat = 0.1, mx = -1;
        for (int i=0; i<50000; i++) {
            mx = -1;
            int mxIdx = -1;
            for (int j=0; j<3; j++) {
                double dist = (xx-coords[j].X)*(xx-coords[j].X)+(yy-coords[j].Y)*(yy-coords[j].Y);
                if (dist > mx) {
                    mx = dist;
                    mxIdx = j;
                }
            }
            xx += (coords[mxIdx].X-xx)*rat;
            yy += (coords[mxIdx].Y-yy)*rat;
            rat *= 0.998;
        }
        printf("Case #%d: %.2f %.2f\n", t, xx, yy);
    }
    return 0;
}