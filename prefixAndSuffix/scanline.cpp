#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    vector<int> arr(n, 0);
    vector<int> prefix(n+1, 0);
    cout << "Enter contents:\n";
    for(int i = 0;i<n;i++) cin >> arr[i];
    int q;
    cout << "Enter number of queries: ";
    cin >> q;
    int l, r, x;
    while(q--) {
        cout << "Enter l, r and x: ";
        cin >> l >> r >> x;
        prefix[l] += x;
        prefix[r+1] -= x;
    }
    int count = 0;
    for(int i = 0;i<n+1;i++) {
        count += prefix[i];
        arr[i] += count;
    }
    cout << "The updated array is:\n";
    for(auto it: arr) cout << it << " ";
    return 0;
}