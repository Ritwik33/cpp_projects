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
        vi arr(n);
        for(auto &it:arr) cin >> it;
        sort(arr.begin(), arr.end());
        cout << max((arr[n-1] - arr[0])*arr[n-2], (arr[n-2] - arr[0])*arr[n-1]) << '\n';
    }
}

signed main() {
    FIO;
    solve();
    return 0;
}