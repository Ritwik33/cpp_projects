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
       int maxi = INT_MIN;
       int mini = INT_MAX;
       rep(i, 0, n) {
           int temp;
           cin >> temp;
           maxi = max(maxi, temp);
           mini = min(mini, temp);
       }
       cout << maxi - mini << '\n';
   }
}

signed main() {
    FIO;
    solve();
    return 0;
}