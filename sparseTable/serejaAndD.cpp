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

int n, a[100005], diff[100005], dp[100005][17];

void precompute() {
	rep(j, 1, 17) {
		for (int i = 0; i + (1 << j) - 1 < n - 1; i++) {
			dp[i][j] = max(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
		}
	}
}

bool isPossible(int l, int r, int d) {
	int j = log2(r - l + 1);
	return max(dp[l][j], dp[r - (1 << j) + 1][j]) <= d;
}

int binarySearch(int t, int d) {
	int k = upper_bound(a, a + n, t) - a - 1;
	int low = 0, high = k - 1, ans = k;
	while (low <= high) {
		int mid = low + (high - low) / 2;
		if (isPossible(mid, k - 1, d)) ans = mid, high = mid - 1;
		else low = mid + 1;
	}
	return ans;
}

void solve() {
	cin >> n;
	rep(i, 0, n) cin >> a[i];
	rep(i, 0, n - 1) {
		diff[i] = a[i + 1] - a[i];
		dp[i][0] = diff[i];
	}
	precompute();
	int m; cin >> m;
	while (m--) {
		int t, d; cin >> t >> d;
		cout << binarySearch(t, d) + 1 << endl;
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