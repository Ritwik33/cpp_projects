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
        string s;
        cin >> s;
        int cnt0 = 0, cnt1 = 0;
        rep(i, 0, n) {
            (s[i] == '0') ? cnt0++ : cnt1++;
        }
        if(cnt0 == 0 || cnt1 == 0) {
            cout << 0 << '\n';
        } else {
            cout << min(cnt0, cnt1) - 1 << '\n';
        }
    }
}

signed main() {
    FIO;
    solve();
    return 0;
}