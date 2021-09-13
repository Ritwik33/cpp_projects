#include<bits/stdc++.h>
using namespace std;

int main() {
    long long base, n, ans = 1;
    cin >> base >> n;
    while(n>0) {
        if(n%2 == 0) {
            base = base*base;
            n = n/2;
        } else if(n%2 != 0) {
            ans = ans*base;
            n = n-1;
        }
    }
    cout << ans;
    return 0;
}