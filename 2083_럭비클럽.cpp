#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

int main() {

    vector<string> name;
    vector<int> age, weight;

    while (true) {
        char n[11];
        int a, w;
        scanf("%s %d %d", n, &a, &w);
        if (strcmp(n, "#") == 0) break;
        name.push_back(n);
        age.push_back(a);
        weight.push_back(w);
    }

    for (int i=0; i<name.size(); i++) {
        printf("%s ", name[i].c_str());
        if (age[i] > 17 || weight[i] >=80) 
            printf("Senior\n");
        else printf("Junior\n");
    }
    return 0;
}