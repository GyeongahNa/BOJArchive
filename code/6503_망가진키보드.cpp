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
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int main() {

    while (true) {
        int m;
        cin >> m;
        if (!m) break;
        cin.ignore();
        string s;
        getline(cin, s);

        vector<int> nAlpha(128, 0);
        int left = 0, right = -1, cnt = 0, ans = 0;

        while (right < (int)s.size()) {
            
            if (cnt <= m) {
                ans = max(ans, right-left+1);
                right++;
                if (right >= (int)s.size()) break;
                int ridx = int(s[right]);
                if (nAlpha[ridx] <= 0) cnt++;
                nAlpha[ridx]++;
            }
            else {
                int lidx = int(s[left]);
                nAlpha[lidx]--;
                if (nAlpha[lidx] <= 0) cnt--;
                left++;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}