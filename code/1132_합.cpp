#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <stack>
#include <deque>
#include <iostream>

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

struct Alpha {
    char ch;
    ll val = 0;
    bool isFront = false;
};

int N;
string s;
vector<Alpha> info;

bool cmp(Alpha a, Alpha b) {
    return a.val > b.val;
}

void getInput() {

    for (char c='A'; c<='J'; c++) {
        Alpha alpha;
        alpha.ch = c;
        info.push_back(alpha);
    }

    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> s;
        ll d = 1;
        for (int j=(int)s.size()-1; j>=0; j--) {
            Alpha& alpha = info[s[j]-'A'];
            alpha.val += d;
            if (j == 0) alpha.isFront = true;
            d *= 10;
        }
    }

    sort(info.begin(), info.end(), cmp);
}

int main() {

    getInput();

    int pos = 9;
    while (pos >= 0 && info[pos].isFront) --pos;

    ll tot = 0;
    for (int i=0; i<pos; i++)
        tot += info[i].val * (9-i);
    
    for (int i=pos+1; i<=9; i++)
        tot += info[i].val * (9-i+1);

    cout << tot << endl;
    return 0;
}