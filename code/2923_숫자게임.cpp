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

int N, a, b;
vector<int> A(101), B(101);

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> N;
    for (int i=0; i<N; i++) {

        cin >> a >> b;
        A[a]++;
        B[b]++;

        vector<int> Acpy = A;
        vector<int> Bcpy = B;

        int aidx = 1, bidx = 100, mx = 0;
        while (aidx <= 100 && bidx >= 1) {
            while (aidx <= 100 && !Acpy[aidx]) aidx++;
            while (bidx >= 1 && !Bcpy[bidx]) bidx--;
            if (aidx <= 100 && bidx >= 1) {
                mx = max(aidx+bidx, mx);
                int numRemove = min(Acpy[aidx], Bcpy[bidx]);
                Acpy[aidx] -= numRemove;
                Bcpy[bidx] -= numRemove;
            }
        }
        cout << mx << '\n';
    }
    return 0;
}