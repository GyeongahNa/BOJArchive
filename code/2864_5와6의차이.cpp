#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
using namespace std;

string getNewStr(string n, char before, char after) {

    string res;

    res = "";
    for (int i = 0; i < n.size(); i++) {
        if (n[i] == before)
            res += after;
        else
            res += n[i];
    }
    return res;
}


int main() {

    string n1, n2;

    cin >> n1 >> n2;
    printf("%d ", stoi(getNewStr(n1, '6', '5')) + stoi(getNewStr(n2, '6', '5')));
    printf("%d\n", stoi(getNewStr(n1, '5', '6')) + stoi(getNewStr(n2, '5', '6')));
    return 0;
}