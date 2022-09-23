#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int m, d;
    
    cin >> m >> d;
    if ((m > 2) || ((m == 2) && (d > 18)))
        cout << "After" << endl;
    else if (m == 2 && d == 18)
        cout << "Special" << endl;
    else
        cout << "Before" << endl;
    
    return 0;
}