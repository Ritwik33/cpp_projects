// complexity -> O(1e5 * log mod + q)

#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9 + 7;
int factt[100000];
int modpower[100000];

int ncr(int n, int r) {
    int ans = (((factt[n]*modpower[r])%mod)*modpower[n-r])%mod;
    return ans;
}

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
    modpower[0] = 1;
    for(int i = 1;i<=100000;i++) {
        factt[i] = ((i%mod)*factt[i-1])%mod;
        modpower[i] = power(factt[i], mod-2);
    }
}

signed main() {
    int q;
    cin >> q;
    precompute();
    while(q--) {
        int n, r;
        cin >> n >> r;
        cout << ncr(n, r) << "\n";
    }
    return 0;
}