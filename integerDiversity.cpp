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
        unordered_map<int, int> mpp;
        set<int> st;
        rep(i, 0, n) {
            int temp;
            cin >> temp;
            mpp[temp]++;
            st.insert(temp);
        }
        for(auto it:mpp) {
            if(it.second > 1) {
                st.insert(-(it.first));
            }
        }
        cout << st.size() << '\n';
    }
}

signed main() {
    FIO;
    solve();
    return 0;
}