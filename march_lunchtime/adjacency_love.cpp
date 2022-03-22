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
	vi odds, evens;
	rep(i, 0, n) {
		int val; cin >> val;
		if (val & 1) {
			odds.pb(val);
		} else evens.pb(val);
	}
	if (odds.size() == n) {
		if (n % 2 == 0) {
			for (auto it : odds) cout << it << ' ';
			cout << endl;
		} else {
			cout << "-1" << endl;
		}
		return;
	}
	if (evens.size() == n) {
		cout << "-1" << endl;
		return;
	}
	if (odds.size() == 1) {
		cout << "-1" << endl;
		return;
	}
	if (odds.size() & 1) {
		cout << odds[0] << ' ' << evens[0] << ' ';
		for (int i = 1; i < odds.size(); i++) cout << odds[i] << ' ';
		for (int i = 1; i < evens.size(); i++) cout << evens[i] << ' ';
		cout << endl;
	} else {
		for (auto it : odds) cout << it << ' ';
		for (auto it : evens) cout << it << ' ';
		cout << endl;
	}
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