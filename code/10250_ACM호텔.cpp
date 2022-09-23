#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main() {

    int T, H, W, N, floor, num;
    string re;
    string* vec;

    cin >> T;
    vec = new string[T];
    for (int i = 0; i < T; i++) {
        cin >> H >> W >> N;
        num = ((N - 1) / H + 1);  // 호수
        floor = (N - 1) % H + 1; // 층수
        vec[i] = to_string(floor) + ((num < 10) ? "0" + to_string(num) : to_string(num));
    }

    for (int i = 0; i < T; i++)
        cout << vec[i] << endl;

    delete []vec;
    return 0;
}