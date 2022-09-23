#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int K, N, M, result;

    cin >> K >> N >> M;
    result = K * N - M;
    if (result < 0)
        result = 0;
    
    cout << result << endl;
    return 0;
}