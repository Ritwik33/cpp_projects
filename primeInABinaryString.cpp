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
       string s;
       cin >> s;
       int n = s.size();
       if(n == 1) {
           cout << "No\n";
           continue;
       }
       string prime1 = "10", prime2 = "11";
       int index1, index2;
       index1 = s.find(prime1);
       index2 = s.find(prime2);
       if(index1 > n-2 || index1 < 0) index1 = -1;
       if(index2 > n-2 || index2 < 0) index2 = -1;
       if(index1 != -1 || index2 != -1) {
           cout << "Yes\n";
       } else {
           cout << "No\n";
       }
   }
}

signed main() {
    FIO;
    solve();
    return 0;
}