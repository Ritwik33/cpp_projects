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
       int a[n];
       rep(i, 0, n) cin >> a[i];
       sort(a, a + n);
       int maxi = a[n-1] & a[n-2];
       int temp = maxi;
       int cnt = 0;
       while(temp) {
           if(!(temp & 1)) {
               int val1 = 0, val2 = 0;
               rep(i, 0, n) {
                   if(a[i] & (1 << cnt)) {
                       val1 = a[i];
                       break;
                   }
               }
               rep(i, 0, n) {
                   if((a[i] & (1 << cnt)) && (a[i] != val1)) {
                       val2 = a[i];
                       break;
                   }
               }
               int fact = val1 & val2;
               maxi |= fact;
           }
           cnt++;
           temp >>= 1;
       }
       cout << maxi << '\n';
   }
}

signed main() {
    FIO;
    solve();
    return 0;
}