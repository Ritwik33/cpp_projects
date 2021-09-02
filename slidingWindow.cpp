#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    vector<int> arr(n, 0);
    cout << "Enter contents of the array:\n";
    for(int i = 0;i<n;i++) cin >> arr[i];
    int k;
    cout << "Enter k: ";
    cin >> k; 
    int sum = 0;
    for(int i = 0;i<k;i++) sum += arr[i];
    int max = sum;
    int l = 0, r = k-1;
    while(r != n-1) {
        sum -= arr[l++];
        sum += arr[++r];
        if(sum > max) {
            max = sum;
        }
    }
    cout << "The maximum sum of subsequences taken "<< k <<" at a time is: " << max; 
    return 0;
}