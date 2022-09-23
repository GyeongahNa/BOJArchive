#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <iostream>

using namespace std;

int main() {

    int s1, s2;
    scanf("%d %d", &s1, &s2);

    bool sample = true;
    for (int i=0; i<s1; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        if (x != y) sample = false;
    }

    bool system = true;
    for (int i=0; i<s2; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        if (x != y) system = false;
    }

    if (!sample) printf("Wrong Answer");
    else if (!system) printf("Why Wrong!!!");
    else printf("Accepted");
    return 0;
}