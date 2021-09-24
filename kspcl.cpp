#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;
int fact[100000];

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
    fact[0] = 1;
    for(int i = 1;i<=100000;i++) {
        fact[i] = ((i%mod)*fact[i-1])%mod;
    }
}

int ncr(int n, int r) {
    int nume = fact[n];
    int deno = (fact[n-r]*fact[r])%mod;
    int ans = (nume*power(deno, mod-2))%mod;
    return ans;
}

int strength(int i, int j, int n, int m, int pi) {
    int x1 = ncr(i+j-2, i-1);
    int x2 = ncr(n-i+m-j, m-j);
    return (((x1*x2)%mod)*pi)%mod;
}

signed main() {
    int q;
    cin >> q;
    int sum = 0;
    precompute();
    while(q--) {
        int n, m, k;
        cin >> n >> m >> k;
        while(k--) {
            int xi, yi, pi;
            cin >> xi >> yi >> pi;
            sum += strength(xi, yi, n, m, pi);
        }
    }
    cout << sum;
    return 0;
}