#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main() {

    int N;
    cin >> N;

    vector<int> v;
    for (int i=0; i<N; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }

    sort(v.begin(), v.end());
    for (auto x : v) cout << x << " ";
    return 0;
}