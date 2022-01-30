#include<bits/stdc++.h>
using namespace std;
#define int                                                        long long
#define vi                                                         vector<int>
#define vvi                                                        vector<vector<int>>
#define pb(x)                                                      push_back(x)
#define ppb                                                        pop_back()
#define rep(i, a, b)                                               for(int i = a;i<b;i++)
#define repd(i, a)                                                 for(int i = a;i>=0;i--)
#define setbits(x)                                                 __builtin_popcountll(x)
#define FIO                                                        ios_base::sync_with_stdio(false); cin.tie(NULL);
#define w(t)                                                       int t; cin >> t; while(t--)

int n = 100000;
int spf[100005];
void createSpf() {
    rep(i, 0, n+1) spf[i] = i;
    for(int i = 2;i*i <= n;i++) {
        if(spf[i] != i) continue;
        for(int j = i*i;j <= n; j += i) {
            if(spf[j] == j) spf[j] = i;
        }
    }
}

void printFactors(int n) {
    while(n != 1) {
        cout << spf[n] << ' ';
        n = n/spf[n];
    }
    cout << '\n';
}

void solve() {
   createSpf();
   w(t) {
       int n;
       cin >> n;
       printFactors(n);
   }
}

signed main() {
    FIO;
    solve();
    return 0;
}