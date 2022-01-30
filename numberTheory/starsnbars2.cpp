#include<bits/stdc++.h>
using namespace std;
#define int long long

int ncr(int n, int r) {
    int ans = 1;
    for(int i = 1;i<=((r<n-r)?r:n-r);i++) {
        ans *= (n-i+1)/i;
    }
    return ans;
}

signed main() {
    int n, k;
    cin >> n >> k;
    cout << ncr(n+k-1, k-1);
    return 0;
}