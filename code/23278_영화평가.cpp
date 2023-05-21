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
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

int N, L, H, x;
vector<int> score;

int main() {

    cin >> N >> L >> H;
    for (int i=0; i<N; i++) {
        cin >> x;
        score.push_back(x);
    }

    sort(score.begin(), score.end());

    double sum = 0;
    for (int i=L; i<N-H; i++) {
        sum += score[i];
    }
    
    if (N-L-H == 0) {
        cout << 0;
        return 0;
    }

    printf("%0.10f", sum/(N-L-H));
    return 0;
}