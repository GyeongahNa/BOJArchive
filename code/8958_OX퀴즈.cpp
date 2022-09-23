#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int getScore(const string& rec) {
    
    int sum, con;

    sum = 0;
    con = 0;
    for (int i = 0; i < rec.size(); i++) {
        if (rec[i] == 'X')
            con = 0;
        else if (rec[i] == 'O') {
            con += 1;
            sum += con;
        }
    }
    
    return sum;
}


int main() {

    int N;
    string rec;
    int *score;

    cin >> N;
    score = new int[N];
    for (int i = 0; i < N; i++) {
        cin >> rec;
        score[i] = getScore(rec);
    }
    for (int i = 0; i < N; i++)
        printf("%d\n", score[i]);

    return 0;
}