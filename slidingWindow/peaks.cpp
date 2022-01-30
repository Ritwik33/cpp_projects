#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    vector<int> arr(n, 0);
    cout << "Enter contents of the array:\n";
    for(int i = 0;i<n;i++) cin >> arr[i];
    int k;
    cout << "Enter k: ";
    cin >> k;
    int peaks = 0;
    for(int i = 1;i<k-1;i++) {
        if(arr[i] > arr[i-1] && arr[i] > arr[i+1]) {
            peaks++;
        }
    }
    int max = peaks, index = 0;
    int l = 0, r = k-1;
    while(r != n-1) {
        l++;
        if(arr[l] > arr[l-1] && arr[l] > arr[l+1]) peaks--;
        if(arr[r] > arr[r-1] && arr[r] > arr[r+1]) peaks++;
        r++;
        if(peaks > max) {
            max = peaks;
            index = l;
        }
    }
    cout << index << " " << max;
    return 0;
}