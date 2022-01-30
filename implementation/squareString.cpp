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
        string str;
        cin >> str;
        if(str.size() % 2 != 0) {
            cout << "NO\n";
            continue;
        }
        int mid = str.size()/2;
        int first = 0;
        bool flag = true;
        while(mid < str.size()) {
            if(str[first] != str[mid]) {
                flag = false;
                break;
            }
            first++;
            mid++;
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