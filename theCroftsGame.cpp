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

void solve() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int a[n], b[n];
        rep(i, 0, n) cin >> a[i];
        rep(i, 0, n) cin >> b[i];
        vector<pair<int, int>> profit(n);
        rep(i, 0, n) {
            profit[i] = {a[i] + b[i], i};
        }
        sort(profit.rbegin(), profit.rend());
        int lara = 0, jonah = 0;
        string pick = "lara";
        for(auto it:profit) {
            if(pick == "lara") {
                lara += a[it.second];
                pick = "jonah";
            } else {
                jonah += b[it.second];
                pick = "lara";
            }
        }
        if(lara == jonah) cout << "Tie\n";
        else if(lara > jonah) cout << "First\n";
        else cout << "Second\n";
    }
}

signed main() {
    FIO;
    solve();
    return 0;
}