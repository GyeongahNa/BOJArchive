#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

void swap(int& n1, int& n2) {
    int tmp;

     tmp = n1;
     n1 = n2;
     n2 = tmp;
}

int main() {

    vector<int> v(3);

    cin >> v[0] >> v[1] >> v[2];
    for (int i = 0; i <= 1; i++) {
        if (v[i] > v[i + 1])
            swap(v[i], v[i + 1]);
    }
    if (v[0] > v[1])
        swap(v[0], v[1]);

    printf("%d\n", v[1]);

    return 0;
}