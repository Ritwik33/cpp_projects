// https://codeforces.com/problemset/problem/1458/A

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
#define vvi                                                        vector<vector<int>>
#define pb(x)                                                      push_back(x)
#define ppb                                                        pop_back()
#define rep(i, a, b)                                               for(int i = a;i<b;i++)
#define repd(i, a)                                                 for(int i = a;i>=0;i--)
#define setbits(x)                                                 __builtin_popcountll(x)
#define ps(x, y)                                                   fixed << setprecision(y) << x
#define w(q)                                                       int q; cin >> q; while(q--)
#define FIO                                                        ios_base::sync_with_stdio(false); cin.tie(NULL);

void solve() {
	int n, m; cin >> n >> m;
	int a[n], b[m];
	rep(i, 0, n) cin >> a[i];
	rep(i, 0, m) cin >> b[i];
	int temp = 0;
	int g = 0;
	for (int i = n - 2; i >= 0; i--) {
		g = __gcd(abs(a[i] - a[n - 1]), abs(temp));
		temp = g;
	}
	for (auto it : b) {
		cout << __gcd(abs(g), abs(a[n - 1] + it)) << ' ';
	}
	cout << endl;
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