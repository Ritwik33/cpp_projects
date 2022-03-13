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

int min_coins(int t, vi& deno, vi& dp) {
	if (!t) return dp[t] = 0;
	for (int k : deno) {
		if (k > t) continue;
		dp[t - k] = min_coins(t - k, deno, dp);
		if (dp[t - k] == -1) continue;
		dp[t] = min(dp[t], dp[t - k] + 1);
	}
	if (dp[t] == INT_MAX) return dp[t] = -1;
	return dp[t];
}

void solve() {
	int n, t; cin >> n >> t;
	vi deno(n);
	rep(i, 0, n) cin >> deno[i];
	vi dp(t + 1, INT_MAX);
	cout << min_coins(t, deno, dp) << endl;
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