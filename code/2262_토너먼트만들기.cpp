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
#include <unordered_set>
#include <unordered_map>
#include <cctype>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int N, re;
vector<int> v;

void competeLeft(int idx) {

    re += abs(v[idx]-v[idx-1]);
    v[idx] = min(v[idx], v[idx-1]);
    v.erase(v.begin()+idx-1);
}

void competeRight(int idx) {

    re += abs(v[idx]-v[idx+1]);
    v[idx] = min(v[idx], v[idx+1]);
    v.erase(v.begin()+idx+1);
}

int main() {

    cin >> N;
    for (int i=0; i<N; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }

    while (v.size() >= 2) {
        //랭킹이 가장 낮은 선수 찾기
        int mxIdx = max_element(v.begin(), v.end())-v.begin();

        //왼쪽, 오른쪽 중 랭킹 차이가 더 적은 선수와 경기
        if (mxIdx <= 0) competeRight(mxIdx);
        else if (mxIdx >= v.size()-1) competeLeft(mxIdx);
        else {
            int ldiff = abs(v[mxIdx]-v[mxIdx-1]);
            int rdiff = abs(v[mxIdx]-v[mxIdx+1]);
            if (ldiff <= rdiff) competeLeft(mxIdx);
            else competeRight(mxIdx);
        }
    }

    cout<<re;
    return 0;
}