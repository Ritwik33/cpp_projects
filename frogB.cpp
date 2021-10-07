#include<bits/stdc++.h>
using namespace std;

int frogB(int ind, int n, int k, vector<int>& dp, vector<int>& arr) {
    if(ind == n-1) return dp[ind] = 0;
    if(dp[ind] != -1) return dp[ind];
    int jump = INT_MAX;
    for(int step = 1;step<=k;step++) {
        if(ind+step < n) {
            jump = min(jump, abs(arr[ind] - arr[ind+step]) + frogB(ind+step, n, k, dp, arr));
        } else break;
    }
    return dp[ind] = jump;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0;i<n;i++) cin >> arr[i];
    vector<int> dp(n, -1);
    int k;
    cin >> k;
    cout << frogB(0, n, k, dp, arr) << "\n";
    return 0;
}