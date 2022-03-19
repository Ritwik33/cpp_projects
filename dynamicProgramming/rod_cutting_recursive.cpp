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

int max_amount(int n, vi& prices, vi& dp) {
	if (!n) return dp[n] = 0;
	dp[n] = INT_MIN;
	for (int i = 1; i <= n; i++) {
		if (dp[n - i] == -1) {
			dp[n - i] = max_amount(n - i, prices, dp);
		}
		dp[n] = max(dp[n], prices[i] + dp[n - i]);
	}
	return dp[n];
}

void solve() {
	int n; cin >> n;
	vi prices(n + 1);
	rep(i, 1, n + 1) cin >> prices[i];
	vi dp(n + 1, -1);
	cout << max_amount(n, prices, dp) << endl;
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