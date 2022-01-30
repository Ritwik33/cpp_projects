#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<int> prefix(n);
    for(int i = 0;i<n;i++) arr[i] = i+1;
    for(int i = 0;i<n;i++) {
        prefix[i] = arr[i];
        if(i>0) prefix[i] += prefix[i-1];
    }
    int ans = upper_bound(prefix.begin(), prefix.end(), n) - prefix.begin();
    cout << ans;
    return 0;
}