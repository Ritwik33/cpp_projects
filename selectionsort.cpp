#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0;i<n;i++) cin >> arr[i];
    for(int i = 0;i<n-1;i++) {
        if(arr[i] > arr[i+1]) {
            int key = arr[i+1];
            for(int j = i;j>=0;j--) {
                if(arr[j] > key) {
                    arr[j+1] = arr[j];
                    arr[j] = key;
                }
            }
        }
    }
    cout << "\n";
    for(int itr:arr) cout << itr << " ";
    return 0;
}