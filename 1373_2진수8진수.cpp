#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
using namespace std;

string getOct(string bin) {

    if (bin == "000")
        return "0";
    else if (bin == "001")
        return "1";
    else if (bin == "010")
        return "2";
    else if (bin == "011")
        return "3";
    else if (bin == "100")
        return "4";
    else if (bin == "101")
        return "5";
    else if (bin == "110")
        return "6";
    else
        return "7";
}

int main() {

    string s;
    cin >> s;

    if (s.size() % 3 == 1) 
        s = "00" + s;
    else if (s.size() % 3 == 2)
        s = "0" + s;

    for (int i = 0; i < s.size(); i++) {
        if (i % 3 == 0)
            printf("%s", getOct(s.substr(i, 3)).c_str());
    }
    printf("\n");
    return 0;
}