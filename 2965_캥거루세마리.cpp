#include <iostream>
#include <cstdio>
using namespace std;

int main() {

    int top, mid, bot, itv1, itv2, sum;

    cin >> top >> mid >> bot;
    itv1 = mid - top;
    itv2 = bot - mid;
    
    sum = 0;
    while ((itv1 > 1) || (itv2 > 1)) {
        
        if (itv1 >= itv2) {
            bot = mid;
            mid = top + 1;
        }
        else {
            top = mid;
            mid = bot - 1;
        }

        itv1 = mid - top;
        itv2 = bot - mid;
        sum += 1;
    }

    cout << sum << endl;
    return 0;
}