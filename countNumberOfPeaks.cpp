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

int extremes[11];
void countPeaks(int ind, vi& ds, int n) {
    if(ind == n) {
        if(n >= 3) {
            rep(i, 1, n-1) {
                if((ds[i-1] < ds[i] && ds[i] > ds[i+1]) || (ds[i-1] > ds[i] && ds[i] < ds[i+1])) {
                    extremes[n]++;
                }
            }
            return;
        }
        return;
    }
    rep(i, 0, 3) {
        ds.pb(i);
        countPeaks(ind+1, ds, n);
        ds.ppb; 
    }
}

void solve() {
   w(t) {
       int n;
       cin >> n;
       vi ds;
       countPeaks(0, ds, n);
       cout << extremes[n] << '\n';
   }
}

signed main() {
    FIO;
    solve();
    return 0;
}