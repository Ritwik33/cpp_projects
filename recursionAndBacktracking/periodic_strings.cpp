//https://www.codechef.com/INOIPRAC/problems/INOI1502

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

int power(int a, int n, int m) {
	int ans = 1;
	a %= m;
	while (n) {
		if (n & 1) ans *= a, ans %= m;
		a *= a, a %= m;
		n >>= 1;
	}
	return ans;
}

int f(int n, int m) {
	if (n == 1) return 2;
	int ans = power(2, n, m);
	for (int i = 1; i < n; i++) {
		if (n % i == 0) {
			ans = ans - f(i, m) + m;
			ans %= m;
		}
	}
	return ans;
}

void solve() {
	int n, m; cin >> n >> m;
	cout << f(n, m) << endl;
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