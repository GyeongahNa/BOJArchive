#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <set>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int o, w, n, num, x, y;
bool dead;
char cmd;

int main() {

    num = 1;
    while (true) {
        cin >> o >> w;
        if (o == 0 && w == 0) return 0;

        dead = false;
        while (true) {
            cin >> cmd >> n;
            if (cmd == '#' && n == 0) {
                if (o < w*2 && w < o*2) cout<<num<<" "<<":-)"<<'\n';
                else if (w <= 0) cout<<num<<" "<<"RIP"<<'\n';
                else cout<<num<<" "<<":-("<<'\n';
                break;
            }
            if (w <= 0) dead = true;
            else if (cmd == 'F') w += n;
            else w -= n;
        }
        num++;
    }
    return 0;
}