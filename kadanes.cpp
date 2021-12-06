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
    int maxi = arr[0];
    int sum = 0;
    rep(i, 0, n) {
        sum += arr[i];
        if(sum > maxi) maxi = sum;
        if(sum < 0) sum = 0;
    }
    cout << maxi << "\n";
    return 0;
}