#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int N, C, diff;
    vector<int> w(5000);
    vector<int> chk(100000001);

    cin >> N >> C;
    for (int i = 0; i < N; i++) {
        cin >> w[i];
        chk[w[i]] = 1;
    }

    // 한 개인 경우
    if (chk[C] == 1) {
        cout << 1 << endl;
        return 0;
    }

    // 두 개, 세 개인 경우
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            
            if (w[i] + w[j] == C) {
                cout << 1 << endl;
                return 0;
            } 
            else if (w[i] + w[j] < C) {
                diff = C - w[i] - w[j];
                if ((w[i] != diff) && (w[j] != diff) && (chk[diff] == 1)) {
                    cout << 1 << endl;
                    return 0;
                }
            }
        }
    }

    cout << 0 << endl;
    return 0;
}