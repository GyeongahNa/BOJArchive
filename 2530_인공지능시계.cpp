#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int A, B, C, D;

    cin >> A >> B >> C >> D;
    cout << (A + (B + ((C + D) / 60)) / 60) % 24 << ' ';
    cout << (B + ((C + D) / 60)) % 60  << ' ';
    cout << (C + D) % 60 << endl;

    return 0;
}