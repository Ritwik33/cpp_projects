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
        int c2 = (int)(sqrt(n + 0.5L));
        int c3 = (int)(cbrt(n + 0.5L));
        int c6 = (int)(pow(n + 0.5L, 1.0L/6));
        cout << c2 + c3 - c6 << "\n";
    }
}

signed main() {
    FIO;
    solve();
    return 0;
}