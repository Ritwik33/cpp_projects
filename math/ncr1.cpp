// complexity -> O(1e5 + q*log mod)

#include<bits/stdc++.h>
#define int long long
using namespace std;
int mod = 1e9 + 7;
int factt[100000];

int power(int base, int x) {
    int ans = 1;
    while(x) {
        if(x%2) {
            ans = ((ans%mod)*base)%mod;
            x -= 1;
        } else {
            base = ((base%mod)*base)%mod;
            x /= 2;
        }
    }
    return ans;
}

void precompute() {
    factt[0] = 1;
    for(int i = 1;i<=100000;i++) {
        factt[i] = ((i%mod)*factt[i-1])%mod;
    }
}

int ncr(int n, int r) {
    int nume = factt[n];
    int deno = (factt[r]*factt[n-r])%mod;
    int ans = (nume * power(deno, mod-2))%mod;
    return ans;
}

signed main() {
    int q;
    cin >> q;
    precompute();
    while(q--) {
        int n, r;
        cin >> n >> r;
        cout << ncr(n, r) << endl;
    }
    cout << mod;
    return 0;
}