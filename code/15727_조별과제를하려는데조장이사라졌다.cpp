#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    float L;

    cin >> L;
    cout << (((L / 5) == int(L / 5)) ? int(L / 5) : int(L / 5) + 1) << endl;
    return 0;
}