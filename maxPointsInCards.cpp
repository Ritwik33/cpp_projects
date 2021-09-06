#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for(int i = 0;i<n;i++) cin >> arr[i];
    int k;
    cin >> k;
    int sum = 0;
    for(int i = 0;i<k;i++) sum += arr[i];
    int max = sum;
    int l = 0, r = k-1;
    while(r != n-1) {
        if(--l < 0) l = n-1;
        sum += arr[l];
        sum -= arr[r];
        if(--r < 0) r = n-1;
        if(sum > max) max = sum;
    }
    cout << max;
    return 0;
}