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
	string s, t; cin >> s >> t;
	int n1 = s.length(), n2 = t.length();
	int dp[n1][n2];
	int ans = INT_MIN;
	for (int i = 0; i < n1; i++) {
		for (int j = 0; j < n2; j++) {
			if (s[i] != t[j]) dp[i][j] = 0;
			else {
				dp[i][j] = 1;
				if (i - 1 >= 0 and j - 1 >= 0) {
					dp[i][j] += dp[i - 1][j - 1];
				}
			}
			ans = max(ans, dp[i][j]);
		}
	}
	cout << ans << endl;
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