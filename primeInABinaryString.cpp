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

int n = 3*100000;
int seive[3*100005];
void prepareSeive() {
    for(int i = 2;i<=n;i++) seive[i] = 1;
    for(int i = 0;i*i<=n;i++) {
        if(seive[i] == 0) continue;
        for(int j = i*i;j<=n;j += i) seive[j] = 0;
    }
}

bool isPrime(int val) {
    return seive[val];
}

bool generateSubstrings(string s) {
    int n = s.size();
    rep(i, 0, n) {
        int val = 0;
        rep(j, i, n) {
            val += s[j] - '0';
            if(isPrime(val)) return true;
            val *= 2;
        }
    }
    return false;
}

void solve() {
   prepareSeive();
   w(t) {
       string s;
       cin >> s;
       generateSubstrings(s) == true ? (cout << "Yes\n") : (cout << "No\n");
   }
}

signed main() {
    FIO;
    solve();
    return 0;
}