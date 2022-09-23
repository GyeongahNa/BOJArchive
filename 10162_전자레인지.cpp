#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int T, x, y, z;

    cin >> T;
    
    if (T % 10 != 0) {
        cout << "-1" << endl;
        return 0;
    }

    x = T / 300;
    y = T % 300 / 60;
    z = T % 300 % 60 / 10;

    cout << x << ' ' << y << ' ' << z << endl;
    return 0;
}