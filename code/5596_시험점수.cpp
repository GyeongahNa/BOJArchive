#include <iostream>
using namespace std;

int main() {

    int sum1, sum2, tmp;

    sum1 = 0;
    for (int i = 0; i < 4; i++){
         cin >> tmp;
         sum1 += tmp;
    }

    sum2 = 0;
    for (int i = 0; i < 4; i++) {
        cin >> tmp;
        sum2 += tmp;
    }

    cout << ((sum1 >= sum2) ? sum1 : sum2) << endl;
    return 0;
}