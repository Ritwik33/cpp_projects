#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for(int i = 0;i<n;i++) cin >> arr[i];
    vector<int> prefix(n, 0);
    int temp = 0;
    for(int i = 0;i<n;i++) {
        prefix[i] = arr[i] + temp;
        temp = arr[i];
    }
    
    int q;
    cin >> q;
    int l, r;
    while(q--) {
        cin >> l >> r;
        cout << prefix[r] - prefix[l-1] << "\n";
    }
    return 0;
}