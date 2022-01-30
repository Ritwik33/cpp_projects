#include<bits/stdc++.h>
using namespace std;

int houseRobber(int ind, int flag, vector<int>& arr, vector<vector<int>>& dp, int n) {
    if(ind == n) return dp[ind][flag] = 0;
    if(dp[ind][flag] != -1) return dp[ind][flag];
    if(flag == 0) return dp[ind][flag] = max(arr[ind] + houseRobber(ind+1, 1, arr, dp, n), houseRobber(ind+1, 0, arr, dp, n));
    return dp[ind][flag] = houseRobber(ind+1, 0, arr, dp, n);
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0;i<n;i++) cin >> arr[i];
    vector<vector<int>> dp(n+1, vector<int>(2, -1));
    cout << houseRobber(0, 0, arr, dp, n);
    return 0;
}