// codeforces - contest 576 - div. 1 - problem C

#include<bits/stdc++.h>
using namespace std;

#define endl                                                       '\n'
#define inf                                                        1e18
#define int                                                        long long
#define vi                                                         vector<int>
#define vvi                                                        vector<vector<int>>
#define pb(x)                                                      push_back(x)
#define ppb                                                        pop_back()
#define rep(i, a, b)                                               for(int i = a;i<b;i++)
#define repd(i, a)                                                 for(int i = a;i>=0;i--)
#define setbits(x)                                                 __builtin_popcountll(x)
#define FIO                                                        ios_base::sync_with_stdio(false); cin.tie(NULL);

int b = sqrt(2 * 1000000);

class query {
public:
	int l, r, id;

	bool operator <(const query& q) {
		return (l / b < q.l / b) or (l / b == q.l / b and ((l / b & 1) ? r < q.r : r > q.r));
	}
};

void solve() {
	int n;
	cin >> n;
	vector<query> queries(n);
	rep(i, 0, n) {
		cin >> queries[i].l >> queries[i].r;
		queries[i].id = i + 1;
	}
	sort(queries.begin(), queries.end());
	for (auto q : queries) {
		cout << q.id << ' ';
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