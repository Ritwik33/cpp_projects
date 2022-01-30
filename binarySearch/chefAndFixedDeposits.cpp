#include<bits/stdc++.h>
using namespace std;
#define int                                                        long long
#define vi                                                         vector<int>
#define vvi                                                        vector<vector<int>>
#define pb(x)                                                      push_back(x)
#define ppb                                                        pop_back()
#define rep(i, a, b)                                               for(int i = a;i<b;i++)
#define repd(i, a)                                                 for(int i = a;i>=0;i--)
#define setbits(x)                                                 __builtin_popcountll(x)
#define FIO                                                        ios_base::sync_with_stdio(false); cin.tie(NULL);
#define w(t)                                                       int t; cin >> t; while(t--)

int minFds(vi& prefix, int n, int x) {
    int low = 0, high = n-1;
    while(low <= high) {
        int mid = low + (high - low)/2;
        if(prefix[mid] == x) {
            return mid + 1;
        } else if(prefix[mid] < x) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return low + 1;
}

void solve() {
   w(t) {
       int n, x;
       cin >> n >> x;
       vi a(n);
       int sum = 0;
       rep(i, 0, n) {
           cin >> a[i];
           sum += a[i];
       }
       if(sum < x) {
           cout << -1 << '\n';
           continue;
       } else if(sum == x) {
           cout << n << '\n';
           continue;
       }
       sort(a.rbegin(), a.rend());
       vi prefix(n);
       rep(i, 0, n) {
           prefix[i] = a[i];
           if(i > 0) prefix[i] += prefix[i-1];
       }
       cout << minFds(prefix, n, x) << '\n';
   }
}

signed main() {
    FIO;
    solve();
    return 0;
}