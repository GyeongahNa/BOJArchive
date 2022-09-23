#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int C, K, P, sum;

    cin >> C >> K >> P;
    
    sum = 0;
    for (int i = 1; i <= C; i++)
        sum += K * i + P * i * i;
    cout << sum << endl;

    return 0;
}