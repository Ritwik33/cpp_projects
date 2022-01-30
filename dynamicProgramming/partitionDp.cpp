#include<bits/stdc++.h>
using namespace std;
#define int                                                        long long
#define vi                                                         vector<int>
#define vvi                                                        vector<vector<int>>
#define rep(i, a, b)                                               for(int i = a;i<b;i++)
#define repd(i, a)                                                 for(int i = a;i>=0;i--)
#define setbits(x)                                                 __builtin_popcountll(x)
#define FIO                                                        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int partition(int i, int j, int arr[], vvi& dp) {
    if(i == j) return dp[i][j] = 0;
    if(dp[i][j] != -1) return dp[i][j];
    int mini = INT_MAX;
    rep(k, i, j) {
        int operations = partition(i, k, arr, dp) + partition(k+1, j, arr, dp) + (arr[i-1]*arr[k]*arr[j]);
        mini = min(mini, operations);
    }
    return dp[i][j] = mini;
}

void solve() {
    int n;
    cin >> n;
    int arr[n];
    rep(i, 0, n) cin >> arr[i];
    int numOfMatrices = n-1;
    vvi dp(n, vi(n, -1));
    cout << partition(1, numOfMatrices, arr, dp);
}

signed main() {
    FIO;
    solve();
    return 0;
}