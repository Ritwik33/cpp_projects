#include<bits/stdc++.h>
using namespace std;
 
int main() {
    int n;
    cin >> n;
    int dp[n+1];
    int max = INT_MIN;
    for(int i = 0;i<=n;i++) {
        if(i<=1) dp[i] = i;
        else if((i>=2) && (i%2 == 0)) dp[i] = dp[i/2];
        else if((i>=3) && (i%2 != 0)) dp[i] = dp[(i-1)/2] + dp[(i+1)/2];
        if(dp[i] > max) max = dp[i];
    }
    cout << max;
    return 0;
}