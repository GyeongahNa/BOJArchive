#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

//입력 수의 길이가 30만 인 경우에는 pow 함수 불가
//다른 풀이 찾아보기
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    string oct;
    vector<int> bin;
    long long dec;

    cin >> oct;
    dec = 0;
    for (int i = 0; i < oct.size(); i++) {
        dec += (oct.at(i) - 48) * pow(8, oct.size() - 1 - i);
    }

    if (dec == 0) {
        cout << '0';
        return 0;
    }

    while (dec != 0) {
        bin.push_back(dec % 2);
        dec = dec / 2;
    }

    for (int i = bin.size() - 1; i >= 0; i--)
        cout << bin.at(i);

    return 0;
}