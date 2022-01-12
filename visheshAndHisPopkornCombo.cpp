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
       int a1, a2;
       cin >> a1 >> a2;
       int b1, b2;
       cin >> b1 >> b2;
       int c1, c2;
       cin >> c1 >> c2;
       int a, b, c;
       a = a1 + a2;
       b = b1 + b2;
       c = c1 + c2;
       cout << max(a, max(b, c)) << '\n';
   }
}

signed main() {
    FIO;
    solve();
    return 0;
}