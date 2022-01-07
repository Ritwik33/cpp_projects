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
       int n, d;
       cin >> n >> d;
       int infected;
       if(d <= 10) {
           infected = pow(2, d);
       } else {
           infected = 1024*pow(3, d-10);
       }
       if(infected > INT_MAX || infected < INT_MIN || infected > n) infected = n;
       cout << infected << '\n'; 
   }
}

signed main() {
    FIO;
    solve();
    return 0;
}