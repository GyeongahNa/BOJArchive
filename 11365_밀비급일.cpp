#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
using namespace std;

int main() {

    string s;
    vector<string> v;

    while (true) {
        getline(cin, s, '\n');
        if (strcmp(s.c_str(), "END") == 0)
            break; 
        
        reverse(s.begin(), s.end());
        v.push_back(s);
    }

    for (int i = 0; i < v.size(); i++)
        printf("%s\n", v.at(i).c_str());
    return 0;
}