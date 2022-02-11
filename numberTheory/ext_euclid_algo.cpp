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

int gcd_util(int a, int b) {
	if (!b) return a;
	return gcd_util(b, a % b);
}

int gcd(int a, int b) {
	return gcd_util(abs(a), abs(b));
}

pii extended_euclid_util(int a, int b) {
	if (!b) return {1, 0};
	pii sol = extended_euclid_util(b, a % b);
	return {sol.ss, sol.ff - sol.ss*(a / b)};
}

pii extended_euclid(int a, int b) {
	pii sol = extended_euclid_util(a, b);
	if (a != abs(a)) sol.ff = -sol.ff;
	if (b != abs(b)) sol.ss = -sol.ss;
	return sol;
}

void solve() {
	int a, b; cin >> a >> b;
	pii sol = extended_euclid(a, b);
	cout << sol.ff << ' ' << sol.ss << ' ' << endl;
	cout << gcd(a, b) << ' ' << a*sol.ff + b*sol.ss << endl;
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