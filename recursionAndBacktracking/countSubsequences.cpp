#include<bits/stdc++.h>
using namespace std;

int countSubs(int ind, int arr[], int n) {

    if(ind == n) return 1;

    int pick = countSubs(ind+1, arr, n);

    int not_pick = countSubs(ind+1, arr, n);

    return pick + not_pick;

}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0;i<n;i++) cin >> arr[i];
    vector<int> ds;
    cout << countSubs(0, arr, n);
    return 0;
}