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

int32_t main() {
    FIO;
    w(t) {
        int n; cin >> n;
        int sum1 = 0, sum2 = 0;
        rep(i, 0, 3) {
            rep(j, 0, 3) {
                int temp; cin >> temp;
                if((i == 0 and j == 1) or (i == 0 and j == 2) or (i == 1 and j == 2)) {
                    sum1 += temp;
                }
                if((i == 1 and j == 0) or (i == 2 and j == 0) or (i == 2 and j == 1)) {
                    sum2 += temp;
                }
            }
        }
        cout << max(sum1, sum2) << '\n';
    }
    return 0;
}