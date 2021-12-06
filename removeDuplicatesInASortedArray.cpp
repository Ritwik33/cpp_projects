#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vi2 vector<vector<int>>
#define rep(i, a, b) for(int i = a;i<b;i++)
#define repd(i, a) for(int i = a;i>=0;i--)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int arr[n];
    rep(i, 0, n) cin >> arr[i];
    int cnt = 0;
    rep(i, 1, n) {
        if(arr[i] == arr[i-1]) cnt++;
        else arr[i - cnt] = arr[i];
    }
    rep(i, 0, n - cnt) cout << arr[i] << " ";
    return 0;
}