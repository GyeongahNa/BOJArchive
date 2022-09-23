#include <iostream>
#include <cstdio>
using namespace std;

int main() {

    long long N, B, C, remain, share, sum;
    long long* people;
    
    cin >> N;
    people = new long long[N];
    for (int i = 0; i < N; i++)
        cin >> people[i];
    cin >> B >> C;
    
    sum = 0;
    for (int i = 0; i < N; i++) {
        sum += 1;
        if (people[i] - B > 0) {
            share = (people[i] - B) / C;
            remain = (people[i] - B) % C;
            sum += ((remain > 0) ? (share + 1) : share);
        }
    }
    
    printf("%lld\n", sum);
    delete []people;
    return 0;
}