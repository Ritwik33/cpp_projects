#include<bits/stdc++.h>
using namespace std;

bool wouldOpenOrNot(int ind, int arr[], int n, int sum) {
    if(ind == n) {
        if(sum%360 == 0) return true;
        return false;
    }
    if(wouldOpenOrNot(ind+1, arr, n, sum+arr[ind]) == true) return true;
    if(wouldOpenOrNot(ind+1, arr, n, sum-arr[ind]) == true) return true;
    return false;
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0;i<n;i++) cin >> arr[i];
    if(wouldOpenOrNot(0, arr, n, 0) == true) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}