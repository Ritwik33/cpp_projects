#include<bits/stdc++.h>
using namespace std;

#define endl                                                       '\n'
#define inf                                                        1e18
#define mod                                                        1000000007
#define int                                                        long long
#define vi                                                         vector<int>
#define vvi                                                        vector<vector<int>>
#define pb(x)                                                      push_back(x)
#define ppb                                                        pop_back()
#define rep(i, a, b)                                               for(int i = a;i<b;i++)
#define repd(i, a)                                                 for(int i = a;i>=0;i--)
#define setbits(x)                                                 __builtin_popcountll(x)
#define ps(x, y)                                                   fixed << setprecision(y) << x
#define w(q)                                                       int q; cin >> q; while(q--)
#define FIO                                                        ios_base::sync_with_stdio(false); cin.tie(NULL);

int gcd_util(int a, int b) {
    if(!b) return a;
    return gcd_util(b, a%b);
}

int gcd(int a, int b) {
    return gcd_util(abs(a), abs(b));
}

void solve() {
    cout << gcd(24, 56);
}

int32_t main() {
    FIO;
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}