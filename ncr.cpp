// complexity -> O(q*2n)
#include<bits/stdc++.h>
using namespace std;
#define int long long

int fact(int n) {
    int fact = 1;
    for(int i = 2;i<=n;i++) {
        fact = fact*i;
    }
    return fact;
}

int ncr(int n, int r) {
    int nume = fact(n);
    int deno = fact(r)*fact(n-r);
    int ans = nume/deno;
    return ans;
}

signed main() {
    int q;
    cin >> q; 
    while(q--) {
        int n, r;
        cin >> n >> r;
        cout << ncr(n, r) << endl;
    }
    return 0;
}