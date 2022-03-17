// https://codeforces.com/problemset/problem/1221/D

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
	int n; cin >> n;
	int a[n + 1], b[n + 1];
	rep(i, 1, n + 1) cin >> a[i] >> b[i];
	int dp[n + 1][3];
	dp[1][0] = 0;
	dp[1][1] = b[1];
	dp[1][2] = 2 * b[1];
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 2; j++) {
			dp[i][j] = inf;
			for (int l = 0; l <= 2; l++) {
				if (a[i - 1] + l != a[i] + j) {
					dp[i][j] = min(dp[i][j], j * b[i] + dp[i - 1][l]);
				}
			}
		}
	}
	cout << min({dp[n][0], dp[n][1], dp[n][2]}) << endl;
}

int32_t main() {
	FIO;

// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif

	int q = 1;
	cin >> q;
	while (q--) {
		solve();
	}
	return 0;
}