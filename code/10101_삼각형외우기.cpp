#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int x, y, z;

    cin >> x >> y >> z;
    if ((x + y + z) != 180)
        cout << "Error" << endl;
    else if ((x == 60) && (y == 60) && (z == 60))
        cout << "Equilateral" << endl;
    else if ((x == y) || (x == z) || (y == z))
        cout << "Isosceles" << endl;
    else 
        cout << "Scalene" << endl;

    return 0;
}