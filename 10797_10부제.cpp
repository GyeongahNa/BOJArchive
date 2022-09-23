#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    char day, car;
    int chk;

    cin >> day;
    chk = 0;
    for (int i = 0; i < 5; i++) {
        cin >> car;
        if (day == car)
            chk++;
    }
    cout << chk << endl;
    return 0;
}