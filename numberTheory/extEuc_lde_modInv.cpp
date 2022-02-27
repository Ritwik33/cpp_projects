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

pii extended_euclid_util(int a, int b) {
	if (!b) return {1, 0};
	pii sol = extended_euclid_util(b, a % b);
	return {sol.ss, sol.ff - (a / b)*sol.ss};
}

pii extended_euclid(int a, int b) {
	pii sol = extended_euclid_util(a, b);
	if (a != abs(a)) sol.ff = -sol.ff;
	if (b != abs(b)) sol.ss = -sol.ss;
	return sol;
}

pii solve_lde(int a, int b, int c) {
	pii sol = extended_euclid(a, b);
	int g = __gcd(abs(a), abs(b));
	sol.ff *= (c / g), sol.ss *= (c / g);
	return sol;
}

int modulo_inverse(int num) {
	pii sol = solve_lde(num, mod, 1);
	int mod_inv = (sol.ff % mod + mod) %  mod;
	return mod_inv;
}

int mod_inv[100005];

void precompute_mod_inverse() {
	rep(i, 1, 100005) {
		mod_inv[i] = modulo_inverse(i);
	}
}

void print_multiple_solutions(pii& sol, int a, int b) {
	int n; cin >> n;
	int g = __gcd(abs(a), abs(b));
	rep(k, 0, n) {
		cout << sol.ff + k*(b / g) << ' ' << sol.ss - k*(a / g) << endl;
	}
}

void solve() {

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