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

void reverseString(string& sPrime, int k) {
    int l = 0;
    while(l <= k) {
        swap(sPrime[l], sPrime[k]);
        l++;
        k--;
    }
}

void solve() {
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        string sPrime;
        cin >> sPrime;
        k--;
        while(k >= 0) {
            reverseString(sPrime, k);
            k--;
        }
        cout << sPrime << '\n';
    }
}

signed main() {
    FIO;
    solve();
    return 0;
}