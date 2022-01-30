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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    set<char> ok;
    while(k--) {
        char ch;
        cin >> ch;
        ok.insert(ch);
    }
    vi locations;
    locations.pb(-1);
    rep(i, 0, n) {
        if(!ok.count(s[i])) {
            locations.pb(i);
        }
    }
    locations.pb(n);
    int ans = 0;
    rep(i, 0, locations.size() - 1) {
        int temp = locations[i+1] - locations[i] - 1;
        ans += (temp*(temp+1))/2; 
    }
    cout << ans << '\n';
}

signed main() {
    FIO;
    solve();
    return 0;
}