#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int score;
    char result;

    cin >> score;
    if (score >= 90)
        result = 'A';
    else if (score >= 80)
        result = 'B';
    else if (score >= 70)
        result = 'C';
    else if (score >= 60)
        result = 'D';
    else 
        result = 'F';

    cout << result << endl;
    return 0;
}