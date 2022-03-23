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
#define loop(i, a, b)                                              for(int i = a;i<=b;i++)
#define setbits(x)                                                 __builtin_popcountll(x)
#define ps(x, y)                                                   fixed << setprecision(y) << x
#define w(q)                                                       int q; cin >> q; while(q--)

void file_i_o() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif

}

void solve() {
	int n; cin >> n;
	int power = log2(n);
	int val = pow(2, power);
	int ans = val - log2(val) - 1;
	ans += (n - val);
	cout << ans << endl;
}

int32_t main() {
	file_i_o();
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}