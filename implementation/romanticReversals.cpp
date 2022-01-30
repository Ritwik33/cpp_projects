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
        int n, k;
        cin >> n >> k;
        string sPrime;
        cin >> sPrime;
        vector<char> ans(sPrime.size());
        int maxi = (k & 1) ? k : (k-1);
        int cnt = 1, i = 0;
        ans[k - cnt] = sPrime[i];
        while(cnt != 2) {
            cnt += (cnt & 1) ? 2:-2;
            i++;
            ans[k - cnt] = sPrime[i];
            if(cnt == maxi) {
                cnt += (k & 1) ? 1:3;
            }
        }
        while(k < sPrime.size()) {
            ans[k] = sPrime[k];
            k++;
        }
        for(auto it:ans) cout << it;
        cout << '\n';
    }
}

signed main() {
    FIO;
    solve();
    return 0;
}