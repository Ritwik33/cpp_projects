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
	int n, t; cin >> n >> t;
	int deno[n + 1];
	rep(i, 1, n + 1) cin >> deno[i];
	int dp[t + 1][n + 1];
	for (int i = 0; i <= t; i++) {
		for (int j = 1; j <= n; j++) {
			dp[i][j] = INT_MAX;
			if (j - 1 >= 1) {
				if (dp[i][j - 1] != -1) {
					dp[i][j] = min(dp[i][j], dp[i][j - 1]);
				}
				if (i - deno[j] >= 0) {
					int ans = 1;
					if (dp[i - deno[j]][j - 1] != -1) {
						dp[i][j] = min(dp[i][j], 1 + dp[i - deno[j]][j - 1]);
					}
					dp[i][j] = min(dp[i][j], ans);
				}
			}
			if (dp[i][j] == INT_MAX) dp[i][j] = -1;
		}
	}
	cout << dp[t][n] << endl;
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