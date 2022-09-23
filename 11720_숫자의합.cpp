#include <iostream>
#include <cstdio>
using namespace std;

int main() {

    int N, sum;
    string s;

    cin >> N >> s;
    sum = 0;
    for (int i = 0; i < s.size(); i++)
        sum += s[i] - 48;
    
    printf("%d\n", sum);
    return 0;
}