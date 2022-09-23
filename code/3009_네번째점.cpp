#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

int main() {

    vector<vector<int>> v(3, vector<int>(2));

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++)
            cin >> v[i][j];
    }

    for (int j = 0; j < 2; j++) {
        if (v[0][j] == v[1][j])
            cout << v[2][j] << " ";
        else if (v[0][j] == v[2][j])
            cout << v[1][j] << " ";
        else if (v[1][j] == v[2][j])
            cout << v[0][j] << " ";
    }

    cout << endl;
    return 0;
}