#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int or_h, or_m, add_m;

    cin >> or_h >> or_m >> add_m;
    cout << (or_h + ((or_m + add_m) / 60)) % 24 << ' ';
    cout << ((or_m + add_m) % 60) << endl;

    return 0;
}