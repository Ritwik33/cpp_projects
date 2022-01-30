// complexity -> O(min(row-1, col-1))

#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int row, col;
    cin >> row >> col;
    int ans = 1;
    for(int i = 1;i<=((row-1<col-1)?(row-1):(col-1));i++) ans *= ((row+col-2)-i+1)/i;
    cout << ans;
    return 0;
}