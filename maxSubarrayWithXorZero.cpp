#include<bits/stdc++.h>
using namespace std;

int maxLenOfSubarrayWithXorZero(int arr[], int n) {
    int len, xorr;
    len = xorr = 0;
    unordered_map<int, int> mpp;
    int first, second;
    first = second = -1;
    for(int i = 0;i<n;i++) {
        xorr ^= arr[i];
        if(xorr == 0) {
            len = i+1;
            first = 0;
            second = i;
        } else {
            if(mpp.find(xorr) != mpp.end()) {
                if(i-mpp[xorr] > len) {
                    first = mpp[xorr]+1;
                    second = i;
                }
                len = max(len, i-mpp[xorr]);
            } else {
                mpp[xorr] = i;
            }
        }
    }
    for(int i = first;i<=second;i++) cout << arr[i] << " ";
    cout << "\n";
    return len;
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0;i<n;i++) cin >> arr[i];
    cout << maxLenOfSubarrayWithXorZero(arr, n);
    return 0;
}