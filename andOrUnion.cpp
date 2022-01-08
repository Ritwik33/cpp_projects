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

void solve() {
   w(t) {
       int n;
       cin >> n;
       vi a(n);
       vi bits[30];
       rep(i, 0, n) {
           cin >> a[i];
           rep(j, 0, 30) {
               if(a[i] & (1 << j)) {
                   bits[j].pb(a[i]);
               }
           }
       }
       sort(a.begin(), a.end());
       int ans = a[n-1] & a[n-2];
       int clone = ans;
       int cnt = 0;
       while(clone) {
           if(!(clone & (1 << cnt))) {
               if(bits[cnt].size() >= 2) {
                   ans |= (1 << cnt);
               }
           }
           clone >>= 1;
           cnt++;
       }
       cout << ans << '\n';
   }
}

signed main() {
    FIO;
    solve();
    return 0;
}