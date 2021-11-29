#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define rep(i, a, b) for(int i = a;i<b;i++)

bool chosen[100005];
int numOfPermutations(vi& ds, int arr[], int n) {
    if(ds.size() == n) {
        return 1;
    }
    int count = 0;
    rep(ind, 0, n) {
        if(chosen[arr[ind]]) continue;
        chosen[arr[ind]] = true;
        ds.push_back(arr[ind]);
        count += numOfPermutations(ds, arr, n);
        ds.pop_back();
        chosen[arr[ind]] = false;
    }
    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int arr[n];
    rep(i, 0, n) cin >> arr[i];
    vi ds;
    cout << numOfPermutations(ds, arr, n);
    return 0;
}