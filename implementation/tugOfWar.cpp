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

void ifTheyCanWin() {
        int n, m;
        cin >> n >> m;
        vi a(n);
        vi b(m);
        rep(i, 0, n) cin >> a[i];
        rep(i, 0, m) cin >> b[i];
        sort(b.begin(), b.end());
        vi ans;
        rep(i, 0, n) {
            if(b.empty() || (*(--b.end()) < a[i])) {
                cout << "NO\n";
                return;
            } else if(*(--b.end()) == a[i]) {
                ans.pb(*(--b.end()));
                b.erase(--b.end());
            }
        }
        if(b.empty()) {
            cout << "NO\n";
            return;
        }
        ans.pb(*(--b.end()));
        b.erase(--b.end());
        cout << "YES\n";
        for(auto it:b) cout << it << ' ';
        for(auto it:ans) cout << it << ' ';
        cout << '\n';
}

void solve() {
    int t;
    cin >> t;
    while(t--) {
        ifTheyCanWin();
    }
}

signed main() {
    FIO;
    solve();
    return 0;
}