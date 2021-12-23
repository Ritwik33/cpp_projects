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

void solve1() { // O(n3)
    int n;
    cin >> n;
    vi arr(n);
    for(auto &it:arr) cin >> it;
    int ans = INT_MIN;
    rep(i, 0, n) {
        rep(j, i, n) {
            int sum = 0;
            rep(k, i, j + 1) {
                sum += arr[k];
            }
            ans = max(ans, sum);
        }
    }
    cout << ans << '\n';
}

void solve2() { // O(n2)
    int n;
    cin >> n;
    vi arr(n);
    for(auto &it:arr) cin >> it;
    int ans = INT_MIN;
    rep(i, 0, n) {
        int sum = 0;
        rep(j, i, n) {
            sum += arr[j];
            ans = max(ans, sum);
        }
    }
    cout << ans << '\n';
}

void solve3() { // O(n)
    int n;
    cin >> n;
    vi arr(n);
    for(auto &it:arr) cin >> it;
    int sum = 0, ans = INT_MIN;
    rep(i, 0, n) {
        sum = max(arr[i], sum + arr[i]);
        ans = max(ans, sum);
    }
    cout << ans << '\n';
}

signed main() {
    FIO;
    //solve1();
    // solve2();
    solve3();
    return 0;
}