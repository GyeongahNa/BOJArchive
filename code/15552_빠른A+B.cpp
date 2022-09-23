#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int T, x, y;

    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> x >> y;
        cout << x + y << "\n";
    }
    return 0;
}