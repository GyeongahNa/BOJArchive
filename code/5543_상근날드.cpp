#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    vector<int>burger(3);
    vector<int>drink(2);
    int min;

    for (int i = 0; i < 3; i++)
        cin >> burger.at(i);
    for (int i = 0; i < 2; i++)
        cin >> drink.at(i);

    min = burger.at(0) + drink.at(0);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            if (burger.at(i) + drink.at(j) < min)
                min = burger.at(i) + drink.at(j);
        }
    }
    cout << min - 50 << endl;
    return 0;
}