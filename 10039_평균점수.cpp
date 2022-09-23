#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int score, sum;

    sum = 0;
    for (int i = 0; i < 5; i++) {
        cin >> score;
        if (score < 40)
            score = 40;
        sum += score;
    }
    cout << sum / 5 << endl;
    return 0;
}