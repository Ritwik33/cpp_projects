#include<bits/stdc++.h>
using namespace std;

int main() {
    int q;
    cin >> q;
    while(q--) {
        int n;
        cin >> n;
        int low, high, res, len;
        low = 1;
        high = 1;
        res = low&high;
        len = high-low+1;
        while(high<n) {
            high++;
            res = res&high;
            if(res == 0) {
                res = high;
                low = high;
            } else if(res > 0) {
                if(high-low+1 > len) {
                    len = high-low+1;
                }
            }
        }
        cout << len << "\n";
    }
    return 0;
}