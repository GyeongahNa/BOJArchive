#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int N;
vector<int> v;
vector<int> arr(20);
vector<int> pos(10);
vector<int> cnt(10, 2);

void func(int idx) {

    if (idx >= 2*N) {
        for (int i=0; i<2*N; i++) 
            cout << arr[i] << " ";
        exit(0);
    }

    for (int i=0; i<N; i++) {
        if (!cnt[i]) continue;   
        if (cnt[i] == 2) {
            cnt[i]--;
            pos[i] = idx;
            arr[idx] = v[i];
            func(idx+1);
            cnt[i]++;
        }
        else {
            if (idx-pos[i]-1 != v[i]) continue;
            cnt[i]--;
            arr[idx] = v[i];
            func(idx+1);
            cnt[i]++;
        }
    }
}

int main() {
    
    cin >> N;
    for (int i=0; i<N; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());

    func(0);
    cout << -1;
}