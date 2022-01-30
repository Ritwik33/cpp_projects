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

set<char> vowels {'a', 'e', 'i', 'o', 'u'};

bool isVowel(char ch) {
    return vowels.count(ch);
}

void solve() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string s, p;
        cin >> s >> p;
        int ans = INT_MAX;
        for(char ch = 'a';ch <= 'z'; ch++) {
            int curr = 0;
            for(int i = 0;i<n;i++) {
                char si = (s[i] == '?' ? ch : s[i]);
                char pi = (p[i] == '?' ? ch : p[i]);
                if(si == pi) continue;
                curr += (isVowel(si) != isVowel(pi) ? 1 : 2);
            }
            ans = min(ans, curr);
        }
        cout << ans << "\n";
    }
}

signed main() {
    FIO;
    solve();
    return 0;
}