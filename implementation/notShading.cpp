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
       int n, m, r, c;
       cin >> n >> m >> r >> c;
       r--;
       c--;
       vector<vector<char>> grid(n, vector<char>(m));
       vector<bool> rowHash(m);
       vector<bool> colHash(n);
       int sum = 0;
       rep(i, 0, n) {
           rep(j, 0, m) {
               cin >> grid[i][j];
               if(grid[i][j] == 'B') {
                   rowHash[i] = true;
                   colHash[j] = true;
                   sum++;
               }
           }
       }
       if(grid[r][c] == 'B') {
           cout << 0 << '\n';
           continue;
       }
       if(rowHash[r] || colHash[c]) {
           cout << 1 << '\n';
           continue;
       }
       if(sum) {
           cout << 2 << '\n';
           continue;
       }
       cout << -1 << '\n';
   }
}

signed main() {
    FIO;
    solve();
    return 0;
}