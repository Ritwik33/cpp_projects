#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0;i<n;i++) cin >> arr[i];
    int x;
    cin >> x;
    cout << lower_bound(arr.begin(), arr.end(), x)-arr.begin() << endl;
    // cout << upper_bound(arr.begin(), arr.end(), x)-arr.begin() << endl;
    return 0;
}