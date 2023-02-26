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
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int num[7];

void fillOneTwo(int rabletwo) {

    int rtwo = min(num[2], rabletwo);
    num[2] -= rtwo;
    int lefttwo = rabletwo-rtwo;
    num[1] = max(0, num[1]-lefttwo*4);
}

int main() {

    for (int i=1; i<=6; i++)
        cin >> num[i];

    int cnt = 0;

    //6x6
    cnt += num[6];
    
    //5x5
    cnt += num[5];
    num[1] = max(0, num[1]-num[5]*11);

    //4x4
    cnt += num[4];
    fillOneTwo(num[4]*5);
    
    //3x3
    cnt += num[3]/4;
    if (num[3]%4 == 1) {
        ++cnt;
        fillOneTwo(5);
        num[1] = max(0, num[1]-7);
    }
    else if (num[3]%4 == 2) {
        ++cnt;
        fillOneTwo(3);
        num[1] = max(0, num[1]-6);
    }
    else if (num[3]%4 == 3) {
        ++cnt;
        fillOneTwo(1);
        num[1] = max(0, num[1]-5);
    }

    //2x2;
    cnt += num[2]/9;
    if (num[2]%9) {
        ++cnt;
        num[1] = max(0, num[1]-(36-num[2]%9*4));
    }

    cnt += num[1]/36;
    if (num[1]%36) ++cnt;

    cout << cnt;
    return 0;
}