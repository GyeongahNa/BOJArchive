#include <cstdio>
#include <cstring>
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

#define X first
#define Y second

int N, zero;
long long x;
vector<long long> neg, pos;

int main() {

    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> x;
        if (!x) zero = 1;
        else if (x < 0) neg.push_back(x);
        else pos.push_back(x);
    }

    sort(neg.begin(), neg.end());
    sort(pos.begin(), pos.end(), greater<int>());

    long long re = 0;
    int nsz = neg.size(), psz = pos.size();

    for (int i=0; i<nsz/2*2; i+=2)
        re += neg[i]*neg[i+1];
    if (nsz%2 && !zero) re += neg.back();

    int i = 0;
    for (i=0; i<psz/2*2; i+=2) {
        if (pos[i] == 1 || pos[i+1] == 1) break;
        re += pos[i]*pos[i+1];
    }
    for (int j=i; j<psz; j++) re += pos[j];

    cout << re;
    return 0;
}