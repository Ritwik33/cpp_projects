#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define rep(i, a, b) for(int i = a;i<b;i++)

bool chosen[100005];
void generatePermutations(vi& ds, int arr[], int n) {
    if(ds.size() == n) {
        for(auto it:ds) cout << it << " ";
        cout << "\n";
        return;
    }
    rep(ind, 0, n) {
        if(chosen[arr[ind]]) continue;
        chosen[arr[ind]] = true;
        ds.push_back(arr[ind]);
        generatePermutations(ds, arr, n);
        chosen[arr[ind]] = false;
        ds.pop_back();
    }
 }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int arr[n];
    rep(i, 0, n) cin >> arr[i];
    vi ds;
    generatePermutations(ds, arr, n);
    return 0;
}