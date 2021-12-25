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
        int x, y, z;
        cin >> x >> y >> z;
        if(x+y == z) {
            cout << "EQUAL\n";
        } else if(x+y > z) {
            cout << "TRAIN\n";
        } else {
            cout << "PLANEBUS\n";
        }
    }
}

signed main() {
    FIO;
    solve();
    return 0;
}