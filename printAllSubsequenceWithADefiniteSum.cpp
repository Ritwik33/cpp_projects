#include<bits/stdc++.h>
using namespace std;

void subs(int sum, int ind, vector<int> &ds, int arr[], int n, int s) {
    if(ind == n) {
        if(sum == s) {
            for(auto it:ds) cout << it << " ";
            cout << "\n";
        }
        return;
    }

    //pick...
    ds.push_back(arr[ind]);
    subs(sum+arr[ind], ind+1, ds, arr, n, s);
    ds.pop_back();

    //not-pick...
    subs(sum, ind+1, ds, arr, n, s); 
}

int main() {
    int n;
    cout << "enter size: ";
    cin >> n;

    int arr[n];
    cout << endl << "enter elements:" <<  endl;
    for(int i = 0;i<n;i++) cin >> arr[i];

    int s;
    cout << endl << "enter sum: ";
    cin >> s;

    vector<int> ds;
    cout << endl << "The subsequences with such a sum are:" << endl;
    subs(0, 0, ds, arr, n, s);
    return 0;
}