#include <iostream>
#include <cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    double A, B, C;

    cin >> A >> B >> C;
    if ((C- B == 0) || (A / (C - B)) < 0)
        cout << -1 << endl;
    else
        cout<< int(floor((A / (C - B)) + 1)) << endl;

    return 0;
}