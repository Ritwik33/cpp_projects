#include<bits/stdc++.h>
using namespace std;

int ternarySearch(int low, int high, int arr[], int key) {
    if(low > high) return -1;
    int mid1, mid2;
    mid1 = low + (high-low)/3;
    mid2 = high - (high-low)/3;
    if(key == arr[mid1]) return mid1;
    else if(key == arr[mid2]) return mid2;
    else if(key < arr[mid1]) return ternarySearch(low, mid1-1, arr, key);
    else if((key > arr[mid1]) && (key < arr[mid2])) return ternarySearch(mid1+1, mid2-1, arr, key);
    return ternarySearch(mid2+1, high, arr, key);
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0;i<n;i++) cin >> arr[i];
    int key;
    cin >> key;
    int index = ternarySearch(0, n-1, arr, key);
    if(index == -1) cout << "not found\n";
    else cout << index << "\n";
    return 0;
}