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
#define w(t)                                                       int t; cin >> t; while(t--)

int n = 100000;
char seive[100005];
void createSeive() {
    seive[0] = 'n';
    seive[1] = 'n';
    for(int i = 2;i<=n;i++) seive[i] = 'p';
    for(int i = 2;i*i <= n;i++) {
        if(seive[i] == 'c') continue;
        for(int j = i*i;j<=n;j += i) {
            seive[j] = 'c';
        }
    }
}

void solve() {
   createSeive();
   w(t) {
       int l, r;
       cin >> l >> r;
       for(int i = l;i<=r;i++) {
           if(seive[i] == 'p') cout << i << ' ';          
        }
        cout << '\n';
   }
}

signed main() {
    FIO;
    solve();
    return 0;
}