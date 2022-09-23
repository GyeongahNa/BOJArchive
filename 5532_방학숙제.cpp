#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int L, A, B, C, D, ko_d, ma_d;

    cin >> L >> A >> B >> C >> D;
    ko_d = (A % C > 0) ? A / C + 1 : A / C;
    ma_d = (B % D > 0) ? B / D + 1 : B / D;
    cout << L - ((ko_d > ma_d) ? ko_d : ma_d) << endl;
    return 0;
}