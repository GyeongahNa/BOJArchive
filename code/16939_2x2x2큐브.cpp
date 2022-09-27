#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

vector<int> cube(25);

vector<int> side1 = {13, 14, 5, 6, 17, 18, 21, 22};
vector<int> up1 = {1, 3, 4, 2};

vector<int> side2 = {23, 21, 2, 4, 6, 8, 10, 12};
vector<int> up2 = {17, 19, 20, 18};

vector<int> side3 = {19, 17, 4, 3, 14, 16, 9, 10};
vector<int> up3 = {5, 7, 8, 6};


bool check(vector<int> newcube) {

    for (int i=1; i<=21; i+=4) {
        for (int j=i+1; j<=i+3; j++) {
            if (newcube[j] == newcube[i]) continue;
            return false;
        }
    }
    return true;
}

bool rotate1(vector<int> side, vector<int> up) {

    vector<int> newcube = cube;

    int t1 = newcube[side[6]];
    int t2 = newcube[side[7]];
    int t3 = newcube[up[3]];

    for (int i=7; i>=2; i--)
        newcube[side[i]] = newcube[side[i-2]];
    newcube[side[0]] = t1;
    newcube[side[1]] = t2; 

    for (int i=3; i>=1; i--)
        newcube[up[i]] = newcube[up[i-1]];
    newcube[up[0]] = t3;

    return check(newcube);
}

bool rotate2(vector<int> side, vector<int> up) {

    vector<int> newcube = cube;

    int t1 = newcube[side[0]];
    int t2 = newcube[side[1]];
    int t3 = newcube[up[0]];

    for (int i=0; i<=5; i++)
        newcube[side[i]] = newcube[side[i+2]];
    newcube[side[6]] = t1;
    newcube[side[7]] = t2; 

    for (int i=0; i<=2; i++)
        newcube[up[i]] = newcube[up[i+1]];
    newcube[up[3]] = t3;
    
    return check(newcube);
}

int main() {

    for (int i=1; i<=24; i++) cin >> cube[i];

    if (rotate1(side1, up1)) cout<<1;
    else if (rotate1(side2, up2)) cout<<1;
    else if (rotate1(side3, up3)) cout<<1;
    else if (rotate2(side1, up1)) cout<<1;
    else if (rotate2(side2, up2)) cout<<1;
    else if (rotate2(side3, up3)) cout<<1;
    else cout<<0;
    return 0;
}