#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0;i<n;i++) cin >> arr[i];
    sort(arr, arr+n); // library function for sorting
    for(int i:arr) cout << i << " ";
    return 0;
}