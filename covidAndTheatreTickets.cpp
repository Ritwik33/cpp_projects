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
       int n, m;
       cin >> n >> m;
       int x, y;
       x = (n&1) ? (n/2 + 1) : (n/2);
       y = (m&1) ? (m/2 + 1) : (m/2);
       cout << x*y << '\n';
   }
}

signed main() {
    FIO;
    solve();
    return 0;
}