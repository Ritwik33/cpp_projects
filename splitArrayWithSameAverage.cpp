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
#define FIO                                                        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int dp[30][10000][30];
int isPossible(int ind, int sum1, int n1, int n, int arr[], int sum) {
    if(ind == n) {
        int n2 = n - n1;
        int sum2 = sum - sum1;
        if(n1 == 0 || n2 == 0) return dp[ind][sum1][n1] = 0;
        double avg1, avg2;
        avg1 = (double)sum1/(double)n1;
        avg2 = (double)sum2/(double)n2;
        cout << avg1 << " " << avg2 << "\n";
        if(avg1 == avg2) return dp[ind][sum1][n1] = 1;
        return dp[ind][sum1][n1] = 0;
    }
    if(dp[ind][sum1][n1] != -1) return dp[ind][sum1][n1];
    if(isPossible(ind+1, sum1 + arr[ind], n1 + 1, n, arr, sum)) return dp[ind][sum1][n1] = 1;
    if(isPossible(ind+1, sum1, n1, n, arr, sum)) return dp[ind][sum1][n1] = 1;
    return dp[ind][sum1][n1] = 0;
}

void solve() {
    int n;
    cin >> n;
    int arr[n];
    rep(i, 0, n) cin >> arr[i];
    int sum = 0;
    for(auto it:arr) sum += it;
    memset(dp, -1, sizeof dp);
    if(isPossible(0, 0, 0, n, arr, sum)) cout << "TRUE\n";
    else cout << "NO\n";
}

signed main() {
    FIO;
    solve();
    return 0;
}