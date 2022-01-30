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

void gcdProblem(int n) {
    if(n & 1) {
        int a = (n - 1)/2;
        if(a & 1) cout << (a - 2) << " " << (a + 2) << " " << 1 << "\n";
        else cout << (a - 1) << " " << (a + 1) << " " << 1 << "\n";
    } else {
        cout << n/2 << " " << n/2 - 1 << " " << 1 << "\n";
    }
}

void solve() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        gcdProblem(n);
    }
}

signed main() {
    FIO;
    solve();
    return 0;
}