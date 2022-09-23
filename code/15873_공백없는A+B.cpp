#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    string s, n1, n2;
    int i;

    cin >> s;
    n1 = s[0];
    
    i = 1;
    while (s[i] == '0') {
        n1 += s[i];
        i++;
    }

    n2 = s.substr(i, s.size() - i);
    cout << stoi(n1) + stoi(n2) << endl;
    return 0;
}