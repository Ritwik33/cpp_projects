#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0;i<n;i++) cin >> arr[i];
    for(int i = 0;i<=(1<<n)-1;i++) {
        vector<int> ds;
        for(int j = 0;j<n;j++) {
            if(i & (1<<j)) {
                ds.push_back(arr[j]);
            }
        }
        for(auto itr:ds) cout << itr << " ";
        cout << "\n";
    }
    return 0;
}