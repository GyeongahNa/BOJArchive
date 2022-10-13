#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int T, N;
string s;
vector<char> cube(54);
char col[6] = {'w', 'g', 'r', 'b', 'o', 'y'};

int front[6][8] = 
{
    {0, 1, 2, 5, 8, 7, 6, 3},
    {9, 10, 11, 14, 17, 16, 15, 12},
    {18, 19, 20, 23, 26, 25, 24, 21},
    {27, 28, 29, 32, 35, 34, 33, 30},
    {36, 37, 38, 41, 44, 43, 42, 39},
    {48, 51, 52, 53, 50, 47, 46, 45}
};

int side[6][12] =
{
    {38, 37, 36, 29, 28, 27, 20, 19, 18, 11, 10, 9},
    {0, 3, 6, 18, 21, 24, 51, 48, 45, 44, 41, 38},
    {6, 7, 8, 27, 30, 33, 53, 52, 51, 17, 14, 11},
    {8, 5, 2, 36, 39, 42, 47, 50, 53, 26, 23, 20},
    {2, 1, 0, 9, 12, 15, 45, 46, 47, 35, 32, 29},
    {15, 16, 17, 24, 25, 26, 33, 34, 35, 42, 43, 44}
};


void setCube() {

    int cidx = 0;
    for (int i=0; i<54; i+=9) {
        for (int j=i; j<i+9; j++) 
            cube[j] = col[cidx];
        cidx++;
    }
}

void printUp(const vector<char>& newCube) {

    for (int i=0; i<=6; i+=3) {
        for (int j=i; j<=i+2; j++)
            cout<<newCube[j];
        cout<<endl;
    }
}

int getIdx(string s) {

    if (s[0] == 'U') return 0;
    if (s[0] == 'L') return 1;
    if (s[0] == 'F') return 2;
    if (s[0] == 'R') return 3;
    if (s[0] == 'B') return 4;
    return 5;
}

vector<char> rotate(vector<char> newCube, string s) {

    vector<char> rotated = newCube;

    int idx = getIdx(s);
    int dir = s[1] == '+' ? 1 : -1;

    for (int i=0; i<8; i++) {
        int now = front[idx][i];
        int k = (i+dir*2+8)%8;
        int next = front[idx][k];
        rotated[next] = newCube[now];
    }

    for (int i=0; i<12; i++) {
        int now = side[idx][i];
        int k = (i+dir*3+12)%12;
        int next = side[idx][k];
        rotated[next] = newCube[now];
    }

    return rotated;
}

int main() {

    setCube();

    cin >> T;
    while (T--) {
        cin >> N;
        vector<char> newCube = cube;
        while (N--) {
            cin >> s;
            newCube = rotate(newCube, s);
        }
        printUp(newCube);
    }
    return 0;
}