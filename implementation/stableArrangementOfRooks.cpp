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
       int n, k;
       cin >> n >> k;
       if(k > n/2 + 1) {
           cout << -1 << '\n';
           continue;
       }
       char board[n][n];
       rep(i, 0, n) {
           rep(j, 0, n) {
               board[i][j] = '.';
           }
       }
       int ii = 0, jj = 0;
       while(ii < n && jj < n && k) {
           board[ii][jj] = 'R';
           ii += 2;
           jj += 2;
           k--;
       }
       rep(i, 0, n) {
           rep(j, 0, n) cout << board[i][j];
           cout << '\n';
       }
   }
}

signed main() {
    FIO;
    solve();
    return 0;
}