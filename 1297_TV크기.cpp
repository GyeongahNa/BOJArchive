#include <iostream>
#include <cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    double D, H, W, r;

    cin >> D >> H >> W;
    r = sqrt((D * D) / (W * W + H * H));
    cout << int(H * r) << ' ' << int(W * r) << endl;

    return 0;
}