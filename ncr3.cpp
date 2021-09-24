// complexity -> O(min(r, n-r))
// use this when it is guaranteed that the answer will not overflow
// in other cases use precomputation with complexity -> O(1e5*log mod + q)

#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int n, r;
    cin >> n >> r;
    int ans = 1;
    int count = 0;
    for(int i = 1;i<=((r<n-r)?r:n-r);i++) {
        ans *= (n-i+1)/i;
        count++;
    }
    cout << ans << " " << count;
    return 0;
}