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
	int n, b, x, y; cin >> n >> b >> x >> y;
	int a[n + 1], dp[n + 1];
	dp[0] = a[0] = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i - 1] + x <= b and a[i - 1] + y <= b) {
			dp[i] = max(dp[i - 1] + a[i - 1] + x, dp[i - 1] + a[i - 1] - y);
		} else if (a[i - 1] + x <= b) {
			dp[i] = dp[i - 1] + a[i - 1] + x;
		} else if (a[i - 1] - y <= b) {
			dp[i] = dp[i - 1] + a[i - 1] - y;
		}
		a[i] = dp[i] - dp[i - 1];
	}
	cout << dp[n] << endl;
}

int32_t main() {
	FIO;

// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif

	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}