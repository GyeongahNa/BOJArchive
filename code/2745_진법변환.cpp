#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
using namespace std;

int getDecimal(char c) {
    if (c >= 'A' && c <= 'Z')
        return (10 + (c - 'A'));
    return (c - '0');
}

int main() {

    string N;
    int B, res, dgit;

    cin >> N >> B;
    res = 0;
    for (int i = 0; i < N.size(); i++) {
        dgit = getDecimal(N[i]);
        for (int j = 0; j < N.size() - 1 - i; j++)
            dgit *= B;
        res += dgit;
    }
    printf("%d\n", res);
    return 0;
}