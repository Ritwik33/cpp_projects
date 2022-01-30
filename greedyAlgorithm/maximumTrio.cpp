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
        vi arr(n);
        int highest = INT_MIN, secondHighest = INT_MIN, least = INT_MAX, highestIndex;
        rep(i, 0, n) {
            cin >> arr[i];
            if(arr[i] > highest) {
                highest = arr[i];
                highestIndex = i;
            }
            least = min(least, arr[i]);
        }
        rep(i, 0, n) {
            if(i != highestIndex) {
                secondHighest = max(secondHighest, arr[i]);
            }
        }
        cout << max((highest - least)*secondHighest, (secondHighest - least)*highest) << '\n';
    }
}

signed main() {
    FIO;
    solve();
    return 0;
}