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
#define domain 1000000009

void solve() {
    int t;
    cin >> t;
    while(t--) {
        int x1, x2;
        cin >> x1 >> x2;
        int l = 0, r = domain;
        int n;
        bool flag = false;
        while(l <= r) {
            n = l + (r-l)/2;
            int eq1 = x1 + n;
            int eq2 = x2 + 2*n;
            if(eq1 == eq2) {
                flag = true;
                break;
            } else if(eq2 > eq1) r = n - 1;
            else l = n + 1;
        }
        if(flag) cout << "YES\n";
        else cout << "NO\n"; 
    }
}

signed main() {
    FIO;
    solve();
    return 0;
}