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

int N;
vector<int> score(1000, 0);
vector<int> check(1000, 0);

int main() {

    cin >> N;
    for (int i=0; i<N; i++) cin >> score[i];
    for (int i=0; i<N; i++) cin >> check[i];

    int t1 = 0, t2 = 0;
    for (int i=0; i<N; i++) {
        t1 += score[i];
        if (!check[i]) t2 += score[i];
    }
    cout<<t1<<'\n';
    cout<<t2<<'\n';
    return 0;
}