#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for(int i = 0;i<n;i++) cin >> arr[i];
    vector<int> prefix(n, 0);
    int temp;
    for(int i = 0;i<n;i++) {
        temp = arr[i];
        if(i>0) temp += prefix[i-1];
        prefix[i] = temp;
    }
    int l, r, total = 0;
    for(int k = 1;k<=n;k+=2) {
        l = 0;
        r = k-1;
        while(r < n) {
            total += prefix[r];
            if(l>=1) total -= prefix[l-1];
            l++;
            r++;
        }
    }
    cout << total;
    
    return 0;
}