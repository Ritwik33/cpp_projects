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
       vvi boxes(3, vi(3));
       rep(i, 0, 3) {
           rep(j, 0, 3) cin >> boxes[i][j];
       }
       int ans = 0;
       while(boxes[0][0] != n or boxes[1][1] != n or boxes[2][2] != n) {
           int mini = min(boxes[0][1], boxes[1][0]);
           ans = mini;
           boxes[0][0] += mini;
           boxes[1][1] += mini;
           boxes[0][1] -= mini;
           boxes[1][0] -= mini;
           mini = min(boxes[0][2], boxes[2][0]);
           ans += mini;
           boxes[0][0] += mini;
           boxes[2][2] += mini;
           boxes[0][2] -= mini;
           boxes[2][0] -= mini;
           mini = min(boxes[1][2], boxes[2][1]);
           ans += mini;
           boxes[1][1] += mini;
           boxes[2][2] += mini;
           boxes[1][2] -= mini;
           boxes[2][1] -= mini;
       }
       cout << ans << '\n';
   }
}

signed main() {
    FIO;
    solve();
    return 0;
}