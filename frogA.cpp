#include<bits/stdc++.h>
using namespace std;

int frogARecZeroToN(int ind, vector<int>& arr, vector<int>& dp, int n) {
    if(ind == n-1) return dp[ind] = 0;
    if(dp[ind] != -1) return dp[ind];
    int oneJump = abs(arr[ind] - arr[ind+1]) + frogARecZeroToN(ind+1, arr, dp, n);
    int twoJump = INT_MAX;
    if(ind+2<n) {
        twoJump = abs(arr[ind] - arr[ind+2]) + frogARecZeroToN(ind+2, arr, dp, n);
    }
    return dp[ind] = min(oneJump, twoJump);
}

int frogAItrZeroToN(vector<int>& arr, vector<int>& dp, int n) {
    dp[n-1] = 0;
    for(int ind = n-2;ind>=0;ind--) {
        int oneJump = abs(arr[ind] - arr[ind+1]) + dp[ind+1];
        int twoJump = INT_MAX;
        if(ind+2 < n) {
            twoJump = abs(arr[ind] - arr[ind+2]) + dp[ind+2];
        }
        dp[ind] = min(oneJump, twoJump);
    }
    return dp[0];
}

int frogARecBackToFront(int ind, vector<int>& arr, vector<int>& dp, int n) {
    if(ind == 0) return dp[ind] = 0;
    if(dp[ind] != -1) return dp[ind];
    int oneJump = abs(arr[ind] - arr[ind-1]) + frogARecBackToFront(ind-1, arr, dp, n);
    int twoJump = INT_MAX;
    if(ind-2 >= 0) {
        twoJump = abs(arr[ind] - arr[ind-2]) + frogARecBackToFront(ind-2, arr, dp, n);
    }
    return dp[ind] = min(oneJump, twoJump);
}

int frogAItrBackToFront(vector<int>& arr, vector<int>& dp, int n) {
    dp[0] = 0;
    for(int ind = 1;ind<n;ind++) {
        int oneJump = abs(arr[ind] - arr[ind-1]) + dp[ind-1];
        int twoJump = INT_MAX;
        if(ind-2 >= 0) twoJump = abs(arr[ind] - arr[ind-2]) + dp[ind-2];
        dp[ind] = min(oneJump, twoJump);
    }
    return dp[n-1];
}

void printPath(vector<int>& dp, vector<int>& arr, int n) {
    int ind = 0;
    cout << 0 << " ";
    while(ind != n-1) {
        if(dp[ind] - abs(arr[ind] - arr[ind+1]) == dp[ind+1]) ind += 1;
        else ind += 2;
        cout << ind << " ";
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0;i<n;i++) cin >> arr[i];
    vector<int> dp(n, -1);
    // cout << frogARecZeroToN(0, arr, dp, n);
    // cout << frogAItrZeroToN(arr, dp, n);
    // cout << frogARecBackToFront(n-1, arr, dp, n);
    // cout << frogAItrBackToFront(arr, dp, n);
    cout << frogARecZeroToN(0, arr, dp, n) << "\n";
    printPath(dp, arr, n);
    return 0;
}