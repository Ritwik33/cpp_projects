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

void solve1() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        unordered_map<int, int> freq;
        if(n == 1) freq[1]++;
        else if(n == 2) {
            freq[3]++;
            freq[4]++;
        } else {
            freq[n-2]++;
            freq[2] += (n-1);
        }
        cout << freq.size() << '\n';
        for(auto it:freq) {
            cout << it.first << ' ' << it.second << '\n';
        }
    }
}

void solve2() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        unordered_map<int, int> freq;
        if(n == 1) freq[1]++;
        else if(n == 2) {
            freq[3]++;
            freq[4]++;
        } else {
            if(n & 1) {
                freq[1] += (n-2);
                freq[2]++;
                freq[(n+1)/2]++;
            } else {
                freq[1] += (n-1);
                freq[(n-2)/2]++;
            }
        }
        cout << freq.size() << '\n';
        for(auto it:freq) cout << it.first << ' ' << it.second << '\n';
    }
}

signed main() {
    FIO;
    // solve1();
    solve2();
    return 0;
}