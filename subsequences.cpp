#include<bits/stdc++.h>
using namespace std;

void printSubsequences(int ind, vector<int> &ds, int n, int arr[]) {

    // Print the corresponding sub-sequence...
    if(ind == n) {
        for(auto it:ds) cout<<it<<" ";
        cout << endl;
        return;
    }

    // pick... 
    ds.push_back(arr[ind]);
    printSubsequences(ind+1, ds, n, arr);
    ds.pop_back();

    // not-pick...
    printSubsequences(ind+1, ds, n, arr);

}

int main() {

    int n;
    cout << "Enter size of the array: "; 
    cin >> n;

    int arr[n];
    cout<<endl<<"Enter elements of the array:"<<endl;
    for(int i = 0;i<n;i++) cin >> arr[i];

    vector<int> ds;

    cout<<endl<<"The power sets are:"<<endl;
    printSubsequences(0, ds, n, arr);
    
    return 0;

}