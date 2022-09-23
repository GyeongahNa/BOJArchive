#include <iostream>
using namespace std;

int main() {
    
    int A, B, C, D, P, x, y;

    cin >> A >> B >> C >> D >> P;
    x = A * P;
    y = (P <= C) ? B : B + (P - C) * D;

    cout << ((x > y) ? y : x) << endl;
    return 0;
}