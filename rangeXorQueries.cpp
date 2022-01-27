#include<bits/stdc++.h>
using namespace std;

#define endl                                                       '\n'
#define inf                                                        1e18
#define mod                                                        1000000007
#define int                                                        long long
#define vi                                                         vector<int>
#define vvi                                                        vector<vector<int>>
#define pb(x)                                                      push_back(x)
#define ppb                                                        pop_back()
#define rep(i, a, b)                                               for(int i = a;i<b;i++)
#define repd(i, a)                                                 for(int i = a;i>=0;i--)
#define setbits(x)                                                 __builtin_popcountll(x)
#define ps(x, y)                                                   fixed << setprecision(y) << x
#define w(q)                                                       int q; cin >> q; while(q--)
#define FIO                                                        ios_base::sync_with_stdio(false); cin.tie(NULL);

int n, a[2 * 100005], dp[2 * 100005][18];

void precompute() {
	rep(j, 1, 18) {
		for (int i = 0; i <= n - (1 << j); i++) {
			dp[i][j] = dp[i][j - 1] xor dp[i + (1 << (j - 1))][j - 1];
		}
	}
}

void solve() {
	int q;
	cin >> n >> q;
	rep(i, 0, n) {
		cin >> a[i];
		dp[i][0] = a[i];
	}
	precompute();
	while (q--) {
		int l, r;
		cin >> l >> r;
		l--, r--;
		int ans = 0, len = r - l + 1;
		for (int i = 17; i >= 0; i--) {
			if ((len >> i) & 1) {
				ans = ans xor dp[l][i];
				l += (1 << i);
			}
		}
		cout << ans << endl;
	}
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