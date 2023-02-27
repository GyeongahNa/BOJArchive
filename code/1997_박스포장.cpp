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
#include <climits>
#include <iostream>

using namespace std;
using ii = pair<int, int>;

#define X first
#define Y second


string s;
int N, w, b;
vector<int> h(105, 0), box(105, 0);
vector<vector<ii>> block(105, vector<ii>(105));

void getInput() {

    cin >> N >> w >> b;
    for (int n=0; n<N; n++) {
        for (int j=1; j<=w; j++) {
            block[n][j].X = 0;
            block[n][j].Y = INT_MAX;
        }
    }

    for (int n=0; n<N; n++) {
        cin >> h[n];
        for (int i=h[n]; i>=1; i--) {
            cin >> s;
            for (int j=1; j<=w; j++) {
                if (s[j-1] == 'X') {
                    block[n][j].X = max(block[n][j].X, i);
                    block[n][j].Y = min(block[n][j].Y, i);
                }
            }     
        }
    }
 }

int main() {

    getInput();
    
    int boxh = 0;
    for (int n=0; n<N; n++) {

        int mn = INT_MAX;
        for (int i=1; i<=w; i++) {
            mn = min(mn, boxh+block[n][i].Y-box[i]-1);
            if (boxh+block[n][i].Y-box[i]-1 < 0) cout << "i : " << i << endl;
        }

        int mx = 0;
        vector<int> newbox(w+1, 0);
        for (int i=1; i<=w; i++) {
            newbox[i] = boxh+block[n][i].Y-mn+(block[n][i].X-block[n][i].Y);
            mx = max(mx, newbox[i]);
        }

        if (mx > b) {
            cout << boxh << " ";
            boxh = 0;
            for (int i=0; i<105; i++) box[i] = 0;
            --n;
            continue;
        }
        box = newbox;
        boxh = mx;
    }

    cout << boxh;
    return 0;
}