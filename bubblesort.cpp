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

int cnt = 0; // inversions
void bubbleSort(vi& arr, int n) {
    rep(i, 0, n) {
        rep(j, 0, n-1) {
            if(arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                cnt++;
            }
        }
    }
}

void solve() {
    int n;
    cin >> n;
    vi arr(n);
    for(auto &it:arr) cin >> it;
    bubbleSort(arr, n);
    for(auto it:arr) cout << it << ' ';
    cout << '\n';
    cout << cnt; // total inversions
}

signed main() {
    FIO;
    solve();
    return 0;
}