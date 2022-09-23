#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
using namespace std;

int main() {

    int sm, bg;
    vector<int> v(10);

    sm = 0;
    bg = 0;
    for (int i = 0; i < 10; i++) {
        cin >> v[i];
    }

    for (int i = 0; i < 9; i++) {
        sm += v[i];
        bg = sm + v[i + 1];
        if (bg > 100)
            break;
    }

    if (sm == 100) printf("%d\n", sm);
    else if (100 - sm < bg - 100) printf("%d\n", sm);
    else if (100 - sm > bg - 100) printf("%d\n", bg);
    else printf("%d\n", bg);
    return 0;
}