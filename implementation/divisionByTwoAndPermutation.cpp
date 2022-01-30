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
       set<int> st;
       rep(i, 0, n) {
           st.insert(i+1);
           cin >> a[i];
       }
       rep(i, 0, n) {
           if(st.count(a[i])) {
               st.erase(a[i]);
           } else {
               int temp = a[i];
               while(temp) {
                   temp /= 2;
                   if(st.count(temp)) {
                       st.erase(temp);
                       a[i] = temp;
                       break;
                   }
               }
           }
       }
       sort(a.begin(), a.end());
       bool flag = true;
       rep(i, 0, n) {
           if(a[i] != i+1) {
               flag = false;
               break;
           }
       }
       (flag) ? (cout << "Yes\n") : (cout << "No\n");
   }
}

signed main() {
    FIO;
    solve();
    return 0;
}