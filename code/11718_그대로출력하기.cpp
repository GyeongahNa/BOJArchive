#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
using namespace std;

int main() {

    string s;

    while (true) {
        getline(cin, s, '\n');
        if (s == "")
            break;
        cout << s << endl;
    }
    return 0;
}