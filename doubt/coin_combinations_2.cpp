#include<bits/stdc++.h>
using namespace std;

#define endl                                                       '\n'
#define inf                                                        1e18
#define mod                                                        1000000007
#define int                                                        long long
#define vi                                                         vector<int>
#define pii                                                        pair<int, int>
#define ff                                                         first
#define ss                                                         second
#define mii                                                        map<int, int>
#define umii                                                       unordered_map<int, int>
#define mp 														   make_pair
#define vvi                                                        vector<vector<int>>
#define pb(x)                                                      push_back(x)
#define ppb                                                        pop_back()
#define rep(i, a, b)                                               for(int i = a;i<b;i++)
#define repd(i, a)                                                 for(int i = a;i>=0;i--)
#define setbits(x)                                                 __builtin_popcountll(x)
#define ps(x, y)                                                   fixed << setprecision(y) << x
#define w(q)                                                       int q; cin >> q; while(q--)
#define FIO                                                        ios_base::sync_with_stdio(false); cin.tie(NULL)

void solve() {
	int n, x; cin >> n >> x;
	int coins[n];
	rep(i, 0, n) cin >> coins[i];
	int dp[x + 1][n] = {0};
	for (int i = 0; i <= x; i++) {
		for (int j = 0; j < n; j++) {
			if (i == 0 and j == 0) dp[i][j] = 1;
			if (j - 1 >= 0) {
				dp[i][j] = dp[i][j - 1];
			}
			if (i - coins[j] >= 0) {
				dp[i][j] += dp[i - coins[j]][j];
				dp[i][j] %= mod;
			}
		}
	}
	cout << dp[x][n - 1] << endl;
}

int32_t main() {
	FIO;

// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif

	int t = 1;
	//cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}