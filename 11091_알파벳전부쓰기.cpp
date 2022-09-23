#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <iostream>

using namespace std;

int main() {

    int N;
    scanf("%d", &N);
    cin.ignore();

    while (N--) {

        string s;
        getline(cin, s, '\n');

        vector<bool> v(26, false);
        for (int i=0; i<s.size(); i++) {
            if (s[i] >= 'A' && s[i] <= 'Z')
                v[s[i]+32-'a'] = true;
            else if (s[i] >= 'a' && s[i] <= 'z')
                v[s[i]-'a'] = true;
        }

        string re = "";
        for (int i=0; i<26; i++)
            if (!v[i]) re += 'a'+i;
        if (re == "") printf("pangram\n");
        else printf("missing %s\n", re.c_str());
    }
    return 0;
}