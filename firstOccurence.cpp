#include<bits/stdc++.h>
using namespace std;

int firstOccurence(vector<int>& arr, int key) {
    int n = arr.size();
    int low = 0, high = n-1, mid = (low+high)/2;
    while(low<=high) {
        if(arr[mid] >= key) high = mid-1;
        else if(arr[mid] < key) low = mid+1;
        mid = (low + high)/2;
    }
    if(arr[low] == key) return low;
    return -1;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0;i<n;i++) cin >> arr[i];
    int key;
    cin >> key;
    cout << firstOccurence(arr, key);
    return 0;
}