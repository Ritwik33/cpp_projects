#include<bits/stdc++.h>
using namespace std;

int lastOcc(vector<int>& arr, int key) {
    int n = arr.size();
    int low, high;
    low = 0, high = (n-1);
    int mid = (low+high)/2;
    while(low<=high) {
        if(arr[mid] <= key) low = (mid+1);
        else if(arr[mid] > key) high = (mid-1);
        mid = (low+high)/2;
    }
    if(arr[high] == key) return high;
    return -1;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0;i<n;i++) cin >> arr[i];
    int key;
    cin >> key;
    cout << lastOcc(arr, key);
    return 0;
}