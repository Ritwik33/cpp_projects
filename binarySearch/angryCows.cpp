#include<bits/stdc++.h>
using namespace std;

bool ificanplacemidcows(int arr[], int n, int mid, int cows) {
    int numofcowsplaced = 1;
    int lastcow = arr[0];
    for(int i = 1;i<n;i++) {
        if(arr[i] - lastcow >= mid) {
            numofcowsplaced++;
            lastcow = arr[i];
        }
        if(numofcowsplaced == cows) return true;
    }
    return false;
}

int aggresivecows(int arr[], int n, int cows) {
    sort(arr, arr+n);
    int low = 1, high = arr[n-1] - arr[0];
    while(low<=high) {
        int mid = (low + (high-low)/2);
        if(ificanplacemidcows(arr, n , mid, cows) == true) {
            low = mid+1;
        } else {
            high = mid-1;
        }
    }
    return high;
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0;i<n;i++) cin >> arr[i];
    int cows;
    cin >> cows;
    cout << aggresivecows(arr, n, cows);
    return 0;
}