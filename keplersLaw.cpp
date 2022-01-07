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
       int t1, t2, r1, r2;
       cin >> t1 >> t2 >> r1 >> r2;
       double k1, k2;
       k1 = (double)pow(t1, 2) / (double)pow(r1, 3);
       k2 = (double)pow(t2, 2) / (double)pow(r2, 3);
       k1 == k2 ? (cout << "YES\n") : (cout << "NO\n");
   }
}

signed main() {
    FIO;
    solve();
    return 0;
}