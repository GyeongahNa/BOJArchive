#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    
    int A, B, V, share, remain;

    cin >> A >> B >> V;
    share = (V - B) / (A - B);
    remain = (V - B) % (A - B);
    cout << ((remain == 0) ? share : share + 1) << endl;

    return 0;
}