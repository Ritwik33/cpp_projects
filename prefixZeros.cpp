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

bool isPossible(int ind, const string& s, int k) {
	int diff = 0, operations = 0;
	for (int i = ind; i >= 0; i--) {
		int digit = (s[i] - '0' + operations) % 10;
		int diff = (10 - digit) % 10;
		operations += diff;
	}
	return operations <= k;
}

void solve() {
	int n, k; cin >> n >> k;
	string s; cin >> s;
	int ans = 0, low = 1, high = n;
	while (low <= high) {
		int mid = low + (high - low) / 2;
		if (isPossible(mid - 1, s, k)) low = mid + 1, ans = mid;
		else high = mid - 1;
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
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}