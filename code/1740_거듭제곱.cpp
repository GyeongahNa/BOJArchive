#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

long long getPow(long long n, long long exp) {

    long long re = 1;
    for (long long i=0; i<exp; i++)
        re*=n;
    return re;
}

int main() {

    long long N;
    scanf("%lld", &N);

    long long re = 0, idx=0;
    while (N > 0) {
        if (N%2 == 1)
            re+=getPow(3, idx);
        N/=2;
        idx++;
    }
    printf("%lld\n", re);
}

//배열 + 재귀(메모리 초과)
// #include <iostream>
// #include <cstdio>
// #include <algorithm> 
// #include <cstring>
// #include <vector>
// #include <cmath>
// using namespace std;

// long long getPow(long long exp) {

//     long long num = 1;
//     for (long long i=0; i<exp; i++)
//         num*=3;
//     return num;
// }

// void getNext(vector<long long>& v_bf, long long exp) {
    
//     v_bf.push_back(getPow(exp));
//     int size=v_bf.size()-1;
//     for (long long j=0; j<size; j++) {
//         int num=getPow(exp);
//         num+=v_bf[j];
//         v_bf.push_back(num);
//     }
// }

// int main() {

//     long long N;
//     scanf("%lld", &N);
    
//     long long cnt=0;
//     vector<long long> v_bf;

//     for (long long i=0; i<N; i++) {
        
//         getNext(v_bf, i);
//         cnt=v_bf.size();
//         if (cnt >= N) {
//             printf("%lld\n", v_bf[N-1]);
//             break;
//         }
//     }
//     return 0;
// }

//순차 탐색(시간 초과)
// int main() {

//     long long N;
//     scanf("%lld", &N);

//     long long cnt=0, idx=1;
//     while (cnt < N) {
//         cout<<"idx: "<<idx<<endl;
        
//         long long num=idx;
//         while (num > 0) {
//             if (num%3 == 1) num-=1;
//             if (num%3 != 0) break;
//             num/=3;
//         }
//         if (num == 0) cnt++;
//         idx++;
//     }
//     printf("%lld\n", idx-1);
//     return 0;
// }