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
#define w(x)                                                       int x; cin >> x; while(x--)

void solve() {
   w(t) {
       int a, b, c, d;
       cin >> a >> b >> c >> d;
       int nitin, sobhagya;
       nitin = a;
       sobhagya = b;
       if(sobhagya > nitin) {
           nitin += c;
       } else {
           sobhagya += c;
       }
       if(sobhagya > nitin) {
           nitin += d;
       } else {
           sobhagya += d;
       }
       sobhagya > nitin ? (cout << "S\n") : (cout << "N\n"); 
   }
}

signed main() {
    FIO;
    solve();
    return 0;
}