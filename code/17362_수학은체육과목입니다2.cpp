#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n;

    cin >> n;
    if (n % 8 == 1)
        cout << 1 << endl;
    else if ((n % 8 == 2) || (n % 8 == 0))
        cout << 2 << endl;
    else if ((n % 8 == 3) || (n % 8 == 7))
        cout << 3 << endl;
    else if ((n % 8 == 4) || (n % 8 == 6))
        cout << 4 << endl;
    else if (n % 8 == 5)
        cout << 5 << endl;
    return 0;
}