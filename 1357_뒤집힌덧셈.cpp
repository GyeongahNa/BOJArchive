#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
using namespace std;

int main() {

    string n1, n2, sum;

    cin >> n1 >> n2;
    reverse(n1.begin(), n1.end());
    reverse(n2.begin(), n2.end());
    sum = to_string(stoi(n1) + stoi(n2));
    reverse(sum.begin(), sum.end());
    cout << stoi(sum) << endl;
    return 0;
}