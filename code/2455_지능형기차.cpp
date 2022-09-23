#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

int main() {

    vector<vector<int>> v(4, vector<int>(2));
    vector<int> num(3);

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 2; j++)
            cin >> v[i][j];
    }

    num[0] = v[0][1];
    num[1] = num[0] - v[1][0] + v[1][1];
    num[2] = v[3][0];

    printf("%d\n", max(num[0], max(num[1], num[2])));
    return 0;
}