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
       int a, b, c;
       cin >> a >> b >> c;
       double m1, m2, m3;
       m1 = (double)(((double)(2*b - c))/((double)(a)));
       m2 = (double)(((double)(a + c))/((double)(2*b)));
       m3 = (double)(((double)(2*b - a))/((double)(c)));
       if((m1 > 0.00) && (ceil(m1) == floor(m1))) {
           cout << "Yes\n";
           continue;
       }
       if((m2 > 0.00) && (ceil(m2) == floor(m2))) {
           cout <<"Yes\n";
           continue;
       }
       if((m3 > 0.00) && (ceil(m3) == floor(m3))) {
           cout <<"Yes\n";
           continue;
       }
       cout <<"No\n";
   }
}

signed main() {
    FIO;
    solve();
    return 0;
}