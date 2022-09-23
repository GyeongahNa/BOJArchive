#include <iostream>
#include <vector>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    vector<vector<int>> v(3, vector<int>(6));
    vector<vector<int>> re(3, vector<int>(3));

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 6; j++)
            cin >> v[i][j];
    }

    for (int i = 0; i < 3; i++) {

        if (v[i][5] - v[i][2] < 0) {
            v[i][5] += 60;
            v[i][4] -= 1;
        }

        if (v[i][4] - v[i][1] < 0) {
            v[i][4] += 60;
            v[i][3] -= 1;
        }

        re[i][0] = v[i][3] - v[i][0];
        re[i][1] = v[i][4] - v[i][1];
        re[i][2] = v[i][5] - v[i][2]; 
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << re[i][j];
            if (j != 2)
                cout << ' ';
        }
        cout << endl;
    }

    return 0;
}