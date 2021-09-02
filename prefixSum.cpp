#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter size of the array: ";
    cin >> n;
    vector<int> arr(n, 0);
    cout << "Enter contents:\n";
    for(int i = 0;i<n;i++) cin >> arr[i];
    vector<int> prefix(n, 0);
    for(int i = 0;i<n;i++) {
        if(i == 0) prefix[i] = arr[i];
        else {
            prefix[i] = prefix[i-1] + arr[i];
        }
    }
    cout << "The prefix array is:\n";
    for(auto it:prefix) cout << it << " ";
    cout << "\n";
    int l, r;
    cout << "Enter l and r: ";
    cin >> l >> r;
    cout << "The result is: ";
    cout << prefix[r] - prefix[l-1];
    return 0;
}