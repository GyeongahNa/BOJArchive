#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int T, c;

int main() {

    cin >> T;
    for (int t=0; t<T; t++) {

        cin >> c;
        vector<int> v;
        for (int d=2; d*d<=c; d++) {

            int cnt = 0;
            while (c % d == 0) {
                ++cnt;  
                c /= d;
            }

            for (int i=0; i<=30; i++) {
                int n = cnt&(1<<i);
                if (n) v.push_back(pow(d, n));
            }
        }

        if (c > 1) v.push_back(c);

        sort(v.begin(), v.end());
        for (auto& e : v) cout << e << " ";
        cout << endl;
    }
}
