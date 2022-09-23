#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    long long A, B, num;

    cin >> A >> B;

    num = ((B - A) > 0) ? B - A  + 1 : A - B + 1; 
    if (num % 2 == 0)
        cout << (A + B) * (num / 2) << endl;
    else
        cout << (A + B) * (num / 2) + (A + B) / 2 << endl;
    
    return 0;
}